#include "NPCBuy.h"
#include <thread>

NPCBuy::NPCBuy()
	: NPCBuy(nullptr, nullptr)
{

}

NPCBuy::NPCBuy(BehaviorTree* Tree, FlowNode* NodeParent)
	: TaskNode(Tree, NodeParent)
{
}

NPCBuy::~NPCBuy()
{
}

void NPCBuy::BeginExecute()
{
	NPCBlackBoard* _BlackBoard = static_cast<NPCBlackBoard*>(GetBlackBoard());
	if (_BlackBoard != nullptr) {
	}
}

void NPCBuy::Tick(float DeltaTime) {
	TimeSpent += DeltaTime;

	if (TimeSpent > 5.0f)
	{
		EndExecute();
	}
}

void NPCBuy::EndExecute()
{
	Parent->OnChildEnd(ENodeState::Success);
}
