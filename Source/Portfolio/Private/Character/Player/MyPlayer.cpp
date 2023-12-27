// Copyright Aengchoon


#include "Character/Player/MyPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"

AMyPlayer::AMyPlayer()
{
	const auto PlayerMovement = GetCharacterMovement();
	
	PlayerMovement->bOrientRotationToMovement = true;
	PlayerMovement->RotationRate = FRotator{0.0f, 400.0f, 0.0f};
	PlayerMovement->bConstrainToPlane = true;
	PlayerMovement->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}
