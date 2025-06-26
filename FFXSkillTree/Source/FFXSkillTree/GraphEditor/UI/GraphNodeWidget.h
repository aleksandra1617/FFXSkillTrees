// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GraphNodeWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNodeClicked, FGuid, NodeID);

/**
 * 
 */
UCLASS()
class UGraphNodeWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite);
	FGuid NodeID;
	
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnNodeClicked OnNodeClicked;
	
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> TitleTextBlock;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> NodeButton;
	
	UFUNCTION()
	void HandleClick();
};