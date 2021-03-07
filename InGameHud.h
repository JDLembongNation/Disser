// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Components/WidgetComponent.h"
#include "RecordWidget.h"

#include "InGameHud.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALDIVE_API AInGameHud : public AHUD
{
	GENERATED_BODY()
public: 
	AInGameHud();

	virtual void DrawHUD() override; 

	virtual void BeginPlay() override; 

	virtual void Tick(float DeltaSeconds) override; 

	UFUNCTION()
	void OpenBook(); //Opens the record book that user has created. 

	UFUNCTION()
	void CloseBook();

	UFUNCTION()
	void UpdateDetails(FString Name, FString Description, FString Image);

	UPROPERTY(EditDefaultsOnly, Category="Widgets")
	TSubclassOf<UUserWidget> RecordWidgetClass;

private: 
	URecordWidget* RecordWidget;
};
