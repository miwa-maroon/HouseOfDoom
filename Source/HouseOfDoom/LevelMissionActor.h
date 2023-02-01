// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelMissionActor.generated.h"

UENUM()
enum EMissionType
{
	KillAllEnenies,
	SurviveTime,
};

UENUM(BlueprintType)
enum EEnemyType
{
	Normal UMETA(DisplayName = "Normal"),
	Range UMETA(DisplayName = "Range"),
	MiniBoss UMETA(DisplayName = "MiniBoss"),
	Boss UMETA(DisplayName = "Boss"),
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKilled, EEnemyType, EnemyType);

UCLASS()
class HOUSEOFDOOM_API ALevelMissionActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelMissionActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, Category = "Enemy")
	TEnumAsByte<EMissionType> MissionType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	int NumNormalEnemies;
	UPROPERTY(BlueprintReadWrite, Category = "Enemy")
	int CurrentNumNormalEnemies;
	UPROPERTY(BlueprintReadWrite, Category = "Enemy")
	int SpawnCountNormalEnemies;
	UPROPERTY(BlueprintReadWrite, Category = "Enemy")
	bool bIsAllNormalEnemySpawned;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	int NumRangeEnemies;
	UPROPERTY(BlueprintReadWrite, Category = "Enemy")
	int CurrentNumRangeEnemies;
	UPROPERTY(BlueprintReadWrite, Category = "Enemy")
	int SpawnCountRangeEnemies;
	UPROPERTY(BlueprintReadWrite, Category = "Enemy")
	bool bIsAllRangeEnemySpawned;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	int NumMiniBossEnemies;
	UPROPERTY(BlueprintReadWrite, Category = "Enemy")
	int CurrentNumMiniBossEnemies;
	UPROPERTY(BlueprintReadWrite, Category = "Enemy")
	int SpawnCountMiniBossEnemies;
	UPROPERTY(BlueprintReadWrite, Category = "Enemy")
	bool bIsAllMiniBossEnemySpawned;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	int NumBossEnemies;
	UPROPERTY(BlueprintReadWrite, Category = "Enemy")
	int CurrentNumBossEnemies;
	UPROPERTY(BlueprintReadWrite, Category = "Enemy")
	int SpawnCountBossEnemies;
	UPROPERTY(BlueprintReadWrite, Category = "Enemy")
	bool bIsAllBossEnemySpawned;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	int Time;
	int CurrentTime;
	bool bIsTimeUp;

	float RandRange = 500.0f;
	
	void Initialize();
	
	UFUNCTION(BlueprintCallable)
	void MissionStart();
	UFUNCTION(BlueprintImplementableEvent)
	void MissionComplete();
	UFUNCTION(BlueprintCallable)
	void MissionUpdate();

	bool IsObjectiveComplete(EMissionType EMissionType);

	UFUNCTION(BlueprintCallable)
    void DecreaseNumEnemy(EEnemyType EnemyType);
	
	UFUNCTION(BlueprintImplementableEvent)
    void SpawnEnenies(EEnemyType EnemyType, int NumEnemies, ALevelMissionActor* LevelMissionActor);

	UPROPERTY(BlueprintAssignable)
	FOnKilled OnKilled;

	UFUNCTION(BlueprintImplementableEvent)
	void DestoryAllEnemies();
};
