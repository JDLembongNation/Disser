// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"

#include "RecordWidget.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALDIVE_API URecordWidget : public UUserWidget
{
	GENERATED_BODY()
public: 
	URecordWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override; //Tantamount to Begin Play --> Initialization Directives. 
	void OpenBook(); //Opens the record book that user has created. 
	void CloseBook();
	void UpdateDetails(FString Name, FString Description, FString I
	mage);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta =(BindWidget))
		class UTextBlock* SpeciesName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))	
		class UImage* SpeciesImage; //Point to a blank example image until the code is able to redirect and download the new image.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta= (BindWidget))
		class UTextBlock* SpeciesDescription; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
		class UImage* RecordBackdrop; //The page/book cover image for the records. 	
private: 
bool CheckAllVisualsBinded(); //Method checking that all UMG Components are linked and none are giving nullptr
};
