// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeObstacle.generated.h"

UCLASS()
class TESK1_API ATimeObstacle : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ATimeObstacle();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimeObstacle|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimeObstacle|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimeObstacle|Components")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimeObstacle|Components")
	float MaxRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timeovement")
	int MoveDirection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimeObstacle|Components")
	FVector StartPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimeObstacle|Components")
	FVector CurrentPosition;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimeObstacle")
	float DestroyDelay;

	FTimerHandle DestroyTimerHandle;
	void DestroyActor();

};
