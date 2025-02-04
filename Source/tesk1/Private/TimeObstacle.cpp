// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeObstacle.h"

// Sets default values
ATimeObstacle::ATimeObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

}

// Called when the game starts or when spawned
void ATimeObstacle::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(DestroyTimerHandle, this, &ATimeObstacle::DestroyActor, DestroyDelay, false);
}

// Called every frame
void ATimeObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATimeObstacle::DestroyActor()
{
	Destroy(); 
}