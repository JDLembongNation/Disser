// Fill out your copyright notice in the Description page of Project Settings.


#include "RecordWidget.h"
URecordWidget::URecordWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer){

}

void URecordWidget::NativeConstruct(){
    Super::NativeConstruct(); 
}

void URecordWidget::OpenBook(){
    //Check that Widget is attached (Pointer)
    if(CheckAllVisualsBinded()){
        //Set the visibility to true so Book can be seen. 
        SpeciesName->SetVisibility(ESlateVisibility::Visible);
        SpeciesImage->SetVisibility(ESlateVisibility::Visible);
        SpeciesDescription->SetVisibility(ESlateVisibility::Visible);
        RecordBackdrop->SetVisibility(ESlateVisibility::Visible);
    }
}
void URecordWidget::CloseBook(){
    if(CheckAllVisualsBinded()){
        SpeciesName->SetVisibility(ESlateVisibility::Hidden);
        SpeciesImage->SetVisibility(ESlateVisibility::Hidden);
        SpeciesDescription->SetVisibility(ESlateVisibility::Hidden);
        RecordBackdrop->SetVisibility(ESlateVisibility::Hidden);
    }
}

void URecordWidget::UpdateDetails(FString Name, FString Description, FString Image){
    SpeciesName->SetText(FText::FromString(Name));
    //SpeciesImage->SetText(FText::Format(TEXT(Description))); Image should eb set to UImage
    SpeciesDescription->SetText(FText::FromString(Description));
}


bool URecordWidget::CheckAllVisualsBinded(){
    if(SpeciesName && SpeciesImage && SpeciesDescription && RecordBackdrop) return true;
    else return false;
    //CAN CHANGE TO TERNARY OPERATOR 
}


