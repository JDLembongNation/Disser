// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpMarineHandler.h"
#include "Dom/JsonObject.h"
#include "Book.h"
#include "Misc/FileHelper.h"


// Sets default values for this component's properties
UHttpMarineHandler::UHttpMarineHandler()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Http = &FHttpModule::Get();
	// ...
}


// Called when the game starts
void UHttpMarineHandler::BeginPlay()
{
	InitializeMap();
	HttpCallToDatabase();
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHttpMarineHandler::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHttpMarineHandler::HttpCallToDatabase(){
	UE_LOG(LogTemp, Warning, TEXT("CALL TO DATABASE"));
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UHttpMarineHandler::OnResponseReceived);
	Request->SetURL("https://berwickshiremarinereserve.uk/map/dataJSON.php");
	Request->SetVerb("Get");
	Request->SetHeader(
		TEXT("User-Agent"),
		TEXT("X-UnrealEngine-Agent")
	);
	Request->SetHeader(
		"Content-Type",
		TEXT("application/json")
	);
	Request->ProcessRequest();
}

void UHttpMarineHandler::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool WasSuccessful){

	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
	
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
	UE_LOG(LogTemp, Warning, TEXT("Received Data From Server"));
	if(FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid()){
		/** WORKING CODE. USE THIS AS REFERENCE
		 * bool check = JsonObject->HasField(TEXT("collectionItems"));
			UE_LOG(LogTemp, Warning, TEXT("%i PEYSAR OF THE YEAR CHECK"), check);
		*/
		const TSharedPtr<FJsonObject> Items = JsonObject->GetObjectField("items");
		//Hard Code for now and then dynamically assess what is available. 
		//const TArray<TSharedPtr<FJsonValue>> Items = CollectionItems->GetArrayField("1");
		for(auto& AnimalElements : AnimalIdentifierMap){
			FString Value = TEXT("");
			Value.AppendInt(AnimalElements.Key);
			const TSharedPtr<FJsonObject> SpeciesData = Items->GetObjectField(Value);
			FString data = SpeciesData->GetStringField("Title");
			AddEntry(AnimalElements.Key, data, AnimalElements.Value, "",""); //Description and Image Link need to come from external source.
			
			//Correctly Receiving Data Here.
		}
	}else{
		//Take from local copy of the database. 

		
	}
}
/**
  * Method used to add the entries from the database to the Record Book. 
*/
void UHttpMarineHandler::AddEntry(int32 ID, FString Name, FString Tag, FString Description, FString ImageLink){
	//Fetch information from description and image link here.
	UBook::AddNewEntry(ID, Name, Tag, Description, ImageLink);
}


/**
 * Helper method to populate the AnimalIdentiferMap to be used. Currently Hard Coded since algorithm for determining ID is unknown. 
 */
void UHttpMarineHandler::InitializeMap(){
	AnimalIdentifierMap.Add(224, TEXT("Seal")); //Using Grey Seal as reference as noted in the game environment.
	AnimalIdentifierMap.Add(246,TEXT("Ray")); //Thornback Rays are used as reference.
	AnimalIdentifierMap.Add(4651,TEXT("Dolphin"));
	test.Add(5);
	/* Algorithm for adding animals. Find with key: Type, Value: Species, if true, then Add "Title and Id Number*/
}
