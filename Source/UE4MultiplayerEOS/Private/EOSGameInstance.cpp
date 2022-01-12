// Fill out your copyright notice in the Description page of Project Settings.


#include "EOSGameInstance.h"

#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"

UEOSGameInstance::UEOSGameInstance()
{

}

void UEOSGameInstance::Init()
{
	Super::Init();

	OnlineSubsystem = IOnlineSubsystem::Get();
}

void UEOSGameInstance::CreateSession()
{
	if (OnlineSubsystem)
	{
		IOnlineSessionPtr SessionPtr = OnlineSubsystem->GetSessionInterface();
		if (SessionPtr)
		{
			FOnlineSessionSettings SessionSettings;
			SessionSettings.bIsDedicated = false;
			SessionSettings.bShouldAdvertise = true;
			SessionSettings.bIsLANMatch = true;
			SessionSettings.NumPublicConnections = 5;
			SessionSettings.bAllowJoinInProgress = true;
			SessionSettings.bAllowJoinViaPresence = true;
			SessionSettings.bUsesPresence = true;

			SessionPtr->OnCreateSessionCompleteDelegates.AddUObject(this, &UEOSGameInstance::OnCreateSessionComplete);
			SessionPtr->CreateSession(0, FName("Test Session"), SessionSettings);
		}
	}
}

void UEOSGameInstance::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful)
{
	UE_LOG(LogTemp, Warning, TEXT("Success: %d"), bWasSuccessful);

	if (OnlineSubsystem)
	{
		IOnlineSessionPtr SessionPtr = OnlineSubsystem->GetSessionInterface();
		if (SessionPtr)
		{
			SessionPtr->ClearOnCreateSessionCompleteDelegates(this);
		}
	}
}
