#include "GraphNodeWidget.h"

#include "Components/Button.h"

void UGraphNodeWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	if (NodeButton)
	{
		NodeButton->OnClicked.AddDynamic(this, &UGraphNodeWidget::HandleClick);
	}
}

void UGraphNodeWidget::HandleClick()
{
	UE_LOG(LogTemp, Log, TEXT("Node clicked: %s"), *NodeID.ToString());
	OnNodeClicked.Broadcast(NodeID);
}
