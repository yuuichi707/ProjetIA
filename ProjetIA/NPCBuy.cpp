#include "NPCBuy.h"

NPCBuy::NPCBuy()
	: NPCBuy(nullptr, nullptr)
{

}

NPCBuy::NPCBuy(BehaviorTree* Tree, FlowNode* NodeParent)
	: NPCBuy(Tree, NodeParent)
{
}

NPCBuy::~NPCBuy()
{
}

void NPCBuy::BeginExecute()
{

}
