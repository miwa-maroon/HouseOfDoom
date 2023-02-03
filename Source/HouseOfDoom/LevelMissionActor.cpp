// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelMissionActor.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ALevelMissionActor::ALevelMissionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALevelMissionActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALevelMissionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevelMissionActor::Initialize()
{
	CurrentNumNormalEnemies = 0;
	CurrentNumRangeEnemies = 0;
	CurrentNumMiniBossEnemies = 0;
	CurrentNumBossEnemies = 0;

	SpawnCountNormalEnemies = 0;
	SpawnCountRangeEnemies = 0;
	SpawnCountMiniBossEnemies = 0;
	SpawnCountBossEnemies = 0;
	CurrentTime = Time;
}

void ALevelMissionActor::MissionStart()
{
	Initialize();
	switch(MissionType)
	{
		case EMissionType::KillAllEnenies:
			if(NumNormalEnemies > 0)
            {
				SpawnEnenies(Normal, NumNormalEnemies, this);
            }
			else
			{
				bIsAllNormalEnemySpawned = true;
			}
			
            if(NumRangeEnemies > 0)
            {
            	
            	SpawnEnenies(Range, NumRangeEnemies, this);
            		
            }
            else
            {
	            bIsAllRangeEnemySpawned = true;
            }
        
            if(NumMiniBossEnemies > 0)
            {
	            SpawnEnenies(MiniBoss, NumMiniBossEnemies, this);
            }else
            {
	            bIsAllMiniBossEnemySpawned = true;
            }

			if(NumBossEnemies > 0)
			{
				SpawnEnenies(Boss, NumBossEnemies, this);
			}
			else
			{
				bIsAllBossEnemySpawned = true;
			}
			break;
		case EMissionType::SurviveTime:
			while (bIsTimeUp == false)
			{
			}
			break;
	}
}


void ALevelMissionActor::MissionUpdate()
{
	if(IsObjectiveComplete(MissionType))
	{
		MissionComplete();
	}
}

bool ALevelMissionActor::IsObjectiveComplete(EMissionType EMissionType)
{
	switch(EMissionType)
	{
		case EMissionType::KillAllEnenies:
			if(bIsAllNormalEnemySpawned && bIsAllRangeEnemySpawned && bIsAllMiniBossEnemySpawned && bIsAllBossEnemySpawned && CurrentNumNormalEnemies == 0 && CurrentNumRangeEnemies == 0 && CurrentNumMiniBossEnemies == 0 && CurrentNumBossEnemies == 0)
			{
				UE_LOG(LogTemp, Log, TEXT("Mission Complete"));
				return true;
			}else
			{
				UE_LOG(LogTemp, Log, TEXT("Mission doesnt Complete"));
			}
			break;
		case EMissionType::SurviveTime:
			if(bIsTimeUp)
			{
				return true;
			}
			break;
	}
	return false;
}

void ALevelMissionActor::DecreaseNumEnemy(EEnemyType EnemyType)
{
	switch(EnemyType)
	{
		case EEnemyType::Normal:
			CurrentNumNormalEnemies--;
			break;
		case EEnemyType::Range:
			CurrentNumRangeEnemies--;
			break;
		case EEnemyType::MiniBoss:
			CurrentNumMiniBossEnemies--;
			break;
		case EEnemyType::Boss:
			CurrentNumBossEnemies--;
			break;
	}
	MissionUpdate();
}


