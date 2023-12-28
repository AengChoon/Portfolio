// Copyright Aengchoon


#include "Character/MyEnemy.h"

AMyEnemy::AMyEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

void AMyEnemy::NotifyActorBeginCursorOver()
{
	Super::NotifyActorBeginCursorOver();
	HighlightActor(true);
}

void AMyEnemy::NotifyActorEndCursorOver()
{
	Super::NotifyActorEndCursorOver();
	HighlightActor(false);
}

void AMyEnemy::HighlightActor(const bool bInShouldHighlight)
{
	TInlineComponentArray<USkeletalMeshComponent*> SkeletalMeshComponents{this, true};
	
	for (const auto Iterator : SkeletalMeshComponents)
	{
		if (!IsValid(Iterator)) { continue; }
		Iterator->SetRenderCustomDepth(bInShouldHighlight);
		Iterator->SetCustomDepthStencilValue(bInShouldHighlight ? 250 : 0);
	}
}


