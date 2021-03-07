// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameHud.h"

AInGameHud::AInGameHud(){

}

void AInGameHud::BeginPlay(){
    Super::BeginPlay();
    //Instnatiate the Widget 
    if(RecordWidgetClass){
        RecordWidget = CreateWidget<URecordWidget>(GetWorld(), RecordWidgetClass);
        if(RecordWidget){
            RecordWidget->AddToViewport();
        }
    }
}

void AInGameHud::Tick(float DeltaSeconds){
    Super::Tick(DeltaSeconds);
}

void AInGameHud::DrawHUD(){
    Super::DrawHUD();
}

void AInGameHud::OpenBook(){
    if(RecordWidget){
        RecordWidget->OpenBook();
    }
}

void AInGameHud::CloseBook(){
    if(RecordWidget){
        RecordWidget->CloseBook();
    }
}

void AInGameHud::UpdateDetails(FString Name, FString Description, FString Image){
    if(RecordWidget){
        RecordWidget->UpdateDetails(Name, Description, Image);
    }
}