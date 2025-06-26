#include "GraphWidget.h"
#include "GraphNodeWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"

void UGraphWidget::AddNodeWidget()
{
	if (!GraphCanvas)
		return;
	
	UGraphNodeWidget* NodeWidget = CreateWidget<UGraphNodeWidget>(this, DefaultNodeWidgetClass);
	
	if (!NodeWidget)
		return;

	if (UCanvasPanelSlot* GraphPanelSlot = GraphCanvas->AddChildToCanvas(NodeWidget))
	{
		GraphPanelSlot->SetAutoSize(true);
		GraphPanelSlot->SetPosition(FVector2d(0,0));
	}
}