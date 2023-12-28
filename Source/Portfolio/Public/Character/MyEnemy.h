// Copyright Aengchoon

#pragma once

#include "CoreMinimal.h"
#include "Character/MyCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "MyEnemy.generated.h"

/**
 * 
 */
UCLASS()
class PORTFOLIO_API AMyEnemy : public AMyCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AMyEnemy();
	virtual void NotifyActorBeginCursorOver() override;
	virtual void NotifyActorEndCursorOver() override;
	virtual void HighlightActor(bool bInShouldHighlight) override;
};
