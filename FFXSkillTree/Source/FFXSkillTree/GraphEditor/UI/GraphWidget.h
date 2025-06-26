#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GraphWidget.generated.h"

class UInteractiveGraphDA;
class UCanvasPanel;
class UGraphNodeWidget;
struct FGraphNodeTemplate;

UCLASS()
class FFXSKILLTREE_API UGraphWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	// Unreal does not allow UGraphNodeWidget here so using UUserWidget
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UGraphNodeWidget> DefaultNodeWidgetClass;

	UFUNCTION(BlueprintCallable)
    void AddNodeWidget();
	
protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCanvasPanel> GraphCanvas;
};