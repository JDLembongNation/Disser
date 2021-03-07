// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Book.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VIRTUALDIVE_API UBook : public UActorComponent
{
	GENERATED_BODY()
public:	
	// Sets default values for this component's properties
	UBook();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	static void AddNewEntry(int32 ID, FString Name, FString Tag, FString Description, FString ImageLink);
	struct Species{
	int32 ID;
	FString SpeciesName;
	FString SpeciesTag;
	FString SpeciesDescription; 
	FString SpeciesImageLink;
	bool LocalImageExists; 
	};
	static void GetEntryFromId(int32 identifier, Species& outSpecies);
	static void GetEntryFromTag(FString tag, Species& outSpecies);

private:
	static TArray<Species> Entries;
		
};
