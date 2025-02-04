// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MObstacle.generated.h"

UCLASS()
class TESK1_API AMObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMObstacle();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MObstacle|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MObstacle|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MObstacle|Components")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MObstacle|Components")
	float MaxRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	int MoveDirection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MObstacle|Components")
	FVector StartPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MObstacle|Components")
	FVector CurrentPosition;
	UFUNCTION(BlueprintPure, Category = "Obstacle|Properties")
	float GetMoveSpeed()const;
	
	
};
