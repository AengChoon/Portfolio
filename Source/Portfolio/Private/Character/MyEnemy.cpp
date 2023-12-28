// Copyright Aengchoon


#include "Character/MyEnemy.h"

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

void AMyEnemy::HighlightActor(bool bInShouldHighlight)
{
}
