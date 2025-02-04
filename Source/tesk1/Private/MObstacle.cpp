// Fill out your copyright notice in the Description page of Project Settings.


#include "MObstacle.h"


AMObstacle::AMObstacle()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;
	MoveSpeed = FMath::RandRange(100.0f, 400.0f);
	MaxRange = 500.0f;
}

// Called when the game starts or when spawned
void AMObstacle::BeginPlay()
{
	Super::BeginPlay();
	StartPosition = GetActorLocation();
	CurrentPosition = StartPosition;
	MoveDirection = 1;
}

// Called every frame
void AMObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector NewPosition = GetActorLocation();
	NewPosition += GetActorForwardVector() * MoveSpeed * DeltaTime * MoveDirection;

	if (NewPosition.X > StartPosition.X + MaxRange) {
		NewPosition.X = StartPosition.X + MaxRange;
		MoveDirection = -1; // 방향 반전
	}
	else if (NewPosition.X < StartPosition.X - MaxRange) {
		NewPosition.X = StartPosition.X - MaxRange;
		MoveDirection = 1; // 방향 반전
	}

	SetActorLocation(NewPosition);

}

float AMObstacle::GetMoveSpeed()const
{
	return MoveSpeed;
}