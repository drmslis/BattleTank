// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankGameModeBase.generated.h"

class APawnTurret;
class APawnTank;
class APlayerControllerBase;

UCLASS()
class TOONTANKS_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	private:
		APawnTank* PlayerTank;
		int32 TargetTurrets = 0;
		APlayerControllerBase* PlayerControllerRef;

		int32 GetTargetTurretsCount();
		
		UPROPERTY(BlueprintReadonly, meta = (AllowPrivateAccess = "true"))
		float PlayerMaxHealth = 0;
		UPROPERTY(BlueprintReadonly, meta = (AllowPrivateAccess = "true"))
		float PlayerCurrentHealth = 0;

		void HandleGameStart();
		void HandleGameOver(bool PlayerWon);

	public:

		void ActorDied(AActor* DeadActor);
		void SetPlayerMaxHealth(float);
		void SetPlayerCurrentHealth(float);
		
		UFUNCTION(BlueprintImplementableEvent)	
		void UpdatePlayerHealthBar();
		
	protected: 

		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Loop")
		int32 StartDelay = 3;

		virtual void BeginPlay() override;
		UFUNCTION(BlueprintImplementableEvent)		
		void GameStart();
		UFUNCTION(BlueprintImplementableEvent)
		void GameOver(bool PlayerWon);
		UFUNCTION(BlueprintImplementableEvent)
		void InGameUIShow();
		UFUNCTION(BlueprintImplementableEvent)	
		void UpdateTargetTurrets();
		UFUNCTION(BlueprintPure)
		int32 GetTargetTurrets();
};
