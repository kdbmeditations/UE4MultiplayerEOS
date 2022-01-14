// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "EOSGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UE4MULTIPLAYEREOS_API UEOSGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UEOSGameInstance();

	virtual void Init() override;

	UFUNCTION(BlueprintCallable)
	void CreateSession();

	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);

protected:
	class IOnlineSubsystem* OnlineSubsystem;
};
