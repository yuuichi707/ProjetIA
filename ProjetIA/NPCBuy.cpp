#include "NPCBuy.h"
#include <thread>
#include <iostream>

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
	std::cout << "BEgin";
	TimeSpent = 0;
}

void NPCBuy::Tick(float DeltaTime) {
	TaskNode::Tick(DeltaTime);

	TimeSpent += DeltaTime;
	std::cout << "Time wait = 5s";
	if (TimeSpent > 5.0f)
	{
		EndExecute();
	}
}

void NPCBuy::EndExecute()
{
	Parent->OnChildEnd(ENodeState::Success);
}
