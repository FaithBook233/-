// This code was written by 康子秋

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HomeTower_Base.generated.h"

UCLASS()
class FPS_TESTGAME_API AHomeTower_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHomeTower_Base();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UHealthComponent * HealthComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent * HomeMeshComp;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void TowerDestory();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnHealthChanged(UHealthComponent* HealthComponent, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	
};
