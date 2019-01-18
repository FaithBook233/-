// This code was written by 康子秋

#include "Zombie_Base.h"
#include "Components/HealthComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AZombie_Base::AZombie_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HealthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComp"));
	HealthComp->OnHealthChanged.AddDynamic(this, &AZombie_Base::OnHealthChanged);	//绑定血量响应事件

}

// Called when the game starts or when spawned
void AZombie_Base::BeginPlay()
{
	Super::BeginPlay();
	
	

}

// Called every frame
void AZombie_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AZombie_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AZombie_Base::OnHealthChanged(UHealthComponent * HealthComponent, float Health, float HealthDelta, const UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser)
{
	if (Health <= 0.0f)
	{
		DieSet();
	}
}

void AZombie_Base::DieSet_Implementation()
{
	GetMovementComponent()->StopMovementImmediately();
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	DetachFromControllerPendingDestroy();
	//SetLifeSpan(5.0f);  //设置自动销毁时间
	GetMesh()->SetSimulatePhysics(true);

	/*for (int32 index = 0; index < GunTrenchArray.Num(); index++)
	{
	if (GunTrenchArray[index].IsWeapon())
	{
	GunTrenchArray[index].GetWeapon()->SetCurrentMeshCollision(false);
	}
	}*/
}
bool AZombie_Base::DieSet_Validate()
{
	return true;
}