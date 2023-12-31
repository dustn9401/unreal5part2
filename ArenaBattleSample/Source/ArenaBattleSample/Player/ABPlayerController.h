// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ABPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLESAMPLE_API AABPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AABPlayerController();

	// 블루프린트용 함수들
	UFUNCTION(BlueprintImplementableEvent, Category=Game, meta=(DisplayName="OnGameScoreChangedCpp"))
	void K2_OnGameScoreChanged(int32 NewScore);

	UFUNCTION(BlueprintImplementableEvent, Category=Game, meta=(DisplayName="OnGameClearCpp"))
	void K2_OnGameClear();
	
	UFUNCTION(BlueprintImplementableEvent, Category=Game, meta=(DisplayName="OnGameOverCpp"))
	void K2_OnGameOver();

	UFUNCTION(BlueprintImplementableEvent, Category=Game, meta=(DisplayName="OnGameRetryCpp"))
	void K2_OnGameRetry();

	// GameMode에 의해 호출되는 함수들
	void GameScoreChanged(int32 NewScore);
	void GameClear();
	void GameOver();

	UFUNCTION(BlueprintCallable, Category=Game)
	void OnClickRetry();

protected:
	virtual void BeginPlay() override;

// HUD Section: 블루프린트에서 관리하도록 수정됨 (BP_ABPlayerController)
protected:
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=HUD)
	// TSubclassOf<class UABHUDWidget> HUDWidgetClass;	// 위젯 로드하려면 클래스 정보가 필요

	// UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=HUD)
	// TObjectPtr<class UABHUDWidget> HUDWidget;	// 로드한 hud 위젯 보관용

// Save Game Section
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=SaveGame)
	TObjectPtr<class UABSaveGame> SaveGameInstance;
};
