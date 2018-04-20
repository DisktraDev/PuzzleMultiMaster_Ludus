// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority()) {
		this->SetReplicates(true);
		this->SetReplicateMovement(true); // S'applique � l'actor (lui-m�me)
	}

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ActiveTriggers > 0)
	{
		if (HasAuthority()) // Si mod�le client/server l'autorit� d'exec du code suivant, il est donn� au server
							// Si pas de server l'exec du code est donn� � l'instance -game
		{
			FVector Location = GetActorLocation();
			float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
			float JourneyTravelled = (Location - GlobalStartLocation).Size();

			if (JourneyTravelled >= JourneyLength)
			{
				// Si d�placement >= widgetLocation
				// Alors swap = position de d�part
				// GlobalStartLocation devinet GlobalTargetLocation
				// GlobalTargetLocation devient swap

				FVector Swap = GlobalStartLocation;
				GlobalStartLocation = GlobalTargetLocation;
				GlobalTargetLocation = Swap;
			}

			FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
			Location += FVector(Speed * DeltaTime * Direction);
			SetActorLocation(Location);

			// UE_LOG(LogTemp, Warning, TEXT("Begin called"));
		}
	}
}

void AMovingPlatform::AddActiveTrigger()
{
	ActiveTriggers++;
}

void AMovingPlatform::RemoveActiveTrigger()
{
	if (ActiveTriggers > 0) {
		ActiveTriggers--;
	}
}


