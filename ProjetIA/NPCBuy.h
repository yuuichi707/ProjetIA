#pragma once
#include "FlowNode.h"
#include "BehaviorTree.h"
#include "TaskNode.h"

class NPCBuy : public FlowNode
{
public:
	NPCBuy();
	NPCBuy(BehaviorTree* Tree, FlowNode* NodeParent);
	virtual ~NPCBuy() override;

	virtual void BeginExecute() override;
	virtual void Tick(float DeltaTime) override;
	virtual void EndExecute() override;
};

