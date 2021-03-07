// Fill out your copyright notice in the Description page of Project Settings.


#include "Book.h"

// Sets default values for this component's properties
TArray<UBook::Species> UBook::Entries;

UBook::UBook()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBook::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("THE FUCKING TARRAY WAS ADDED"));

	// ...
	
}


// Called every frame
void UBook::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UBook::AddNewEntry(int32 ID, FString Name, FString Tag, FString Description, FString ImageLink){
	//Find the Path to the image and check if one is available. 
	struct Species Specimen = {ID, Name, Tag, Description, ImageLink, true};
	UE_LOG(LogTemp, Warning, TEXT("%s has been added"),*Name);
	Entries.Add(Specimen);

}

void UBook::GetEntryFromId(int32 identifier, Species& outSpecies){
	for(int32 i = 0; i < Entries.Num(); i++){
		if(Entries[i].ID == identifier) outSpecies = Entries[i];
	}
}

void UBook::GetEntryFromTag(FString tag, Species& outSpecies){
	for(int32 i = 0; i < Entries.Num(); i++){
		if(Entries[i].SpeciesTag.Equals(tag)) outSpecies = Entries[i];
	}
}

