

#include "Obstacle.h"


AObstacle::AObstacle()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

 	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = FMath::RandRange(50.0f, 300.0f);
}


void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}


void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed)) {
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}

float AObstacle::GetRotationSpeed()const
{
	return RotationSpeed;
}