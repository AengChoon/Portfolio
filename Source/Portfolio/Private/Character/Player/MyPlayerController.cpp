// Copyright Aengchoon


#include "Character/Player/MyPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AMyPlayerController::AMyPlayerController()
{
	bReplicates = true;
	bEnableMouseOverEvents = true;
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(PlayerContext);
	
	const auto InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(InputSubsystem);
	InputSubsystem->AddMappingContext(PlayerContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	
	FInputModeGameAndUI InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputMode.SetHideCursorDuringCapture(false);
	SetInputMode(InputMode);
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	const auto EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyPlayerController::Move);
}

void AMyPlayerController::Move(const FInputActionValue& InInputActionValue)
{
	const auto InputAxisVector = InInputActionValue.Get<FVector2D>();
	const FRotator YawRotation{0.0f, GetControlRotation().Yaw, 0.0f};
	const FRotationMatrix YawRotationMatrix{YawRotation};

	const FVector ForwardDirection = YawRotationMatrix.GetUnitAxis(EAxis::X);
	const FVector RightDirection = YawRotationMatrix.GetUnitAxis(EAxis::Y);

	if (const auto ControlledPawn = GetPawn())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}