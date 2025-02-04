#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ItemInterface.generated.h"


UINTERFACE(MinimalAPI)
class UItemInterface : public UInterface
{
	GENERATED_BODY()
};


class TESK1_API IItemInterface
{
	GENERATED_BODY()

public:
	//지뢰 힐링 코인
	//힐링 코인-즉발
	//지뢰 범위내 오버랩 5초뒤 폭발
	UFUNCTION()
	virtual void OnItemOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodeyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) = 0;
	UFUNCTION()
	virtual void OnItemEndOverlap(
		UPrimitiveComponent*OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent*OtherComp,
		int32 OtherBodeyIndex) = 0;
	virtual void ActivateItem(AActor* ActiveActor) = 0;
	virtual FName GetItemType()const = 0;


};
