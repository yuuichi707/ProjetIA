#include "NPCMooveTo.h"

NPCMooveTo::NPCMooveTo()
{
}

NPCMooveTo::NPCMooveTo(NPCBehaviorTree* Tree, FlowNode* NodeParent)
	: TaskNode(Tree, NodeParent)
{

}

NPCMooveTo::~NPCMooveTo()
{
}

void NPCMooveTo::BeginExecute()
{
	NPCBlackBoard* _BlackBoard = static_cast<NPCBlackBoard*>(GetBlackBoard());
	if (_BlackBoard != nullptr) {
		NPCTargetX = _BlackBoard->MarchantX - _BlackBoard->NPCx;
		NPCTargetY = _BlackBoard->MarchantY - _BlackBoard->NPCy;

		NPCDirX = _BlackBoard->NPCx;
		NPCDirY= _BlackBoard->NPCy;

	}
}

void NPCMooveTo::Tick(float DeltaTime)
{
	TaskNode::Tick(DeltaTime);
	
}
