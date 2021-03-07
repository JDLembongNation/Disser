// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "HttpMarineHandler.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VIRTUALDIVE_API UHttpMarineHandler : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHttpMarineHandler();
	
	FHttpModule* Http; //Note to self, "Man the UE4 documentation is sparse. They need to do a lot of work."

	UFUNCTION()
	void HttpCallToDatabase();

	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool WasSuccessful);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private: 
	TMap<int32, FString> AnimalIdentifierMap;
	TArray<int32> test;
	void InitializeMap();
	void AddEntry(int32 ID, FString Name, FString Tag, FString Description, FString ImageLink);
};
