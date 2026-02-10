#pragma once
#include "TaskNode.h"
#include "BehaviorTree.h"
#include "Node.h"
#include "NPC.h"

class NPCMooveTo : public TaskNode
{
public:
	NPCMooveTo();
	NPCMooveTo(NPCBehaviorTree* Tree, FlowNode* NodeParent);
	virtual ~NPCMooveTo() override;

	virtual void BeginExecute() override;
	virtual void Tick(float DeltaTime) override;
	virtual void EndExecute() override;

private:
	float NPCDirX;
	float NPCDirY;

	float NPCTargetX;
	float NPCTargetY;

	NPC* _NPC;

	float DotProductResult;
};

