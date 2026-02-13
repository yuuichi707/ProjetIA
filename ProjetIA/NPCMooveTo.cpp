#include "NPCMooveTo.h"
#include "FlowNode.h"

NPCMooveTo::NPCMooveTo()
{
}

NPCMooveTo::NPCMooveTo(NPCBehaviorTree* Tree, FlowNode* NodeParent)
	: TaskNode(Tree, NodeParent)
{
	TargetUn = false;
}

NPCMooveTo::~NPCMooveTo()
{
}

void NPCMooveTo::BeginExecute()
{
	NPCBlackBoard* _BlackBoard = static_cast<NPCBlackBoard*>(GetBlackBoard());
	if (_BlackBoard != nullptr) {
		
		//Position
		Target1 = { 470, 260 };
		Target2 = { 400, 200 };

		//Character*
		_character = _BlackBoard->_character;
		PosPNJ = _character->rectangle.getPosition();

	}
}

void NPCMooveTo::Tick(float DeltaTime)
{
	TaskNode::Tick(DeltaTime);

	if (PosPNJ.x < Target1.x) {
		PosPNJ.x += Speed * DeltaTime;
	}
	else if (PosPNJ.y > Target1.y) {
		PosPNJ.y -= Speed * DeltaTime;
	}
	if (PosPNJ.x == Target1.x && PosPNJ.y == Target1.y)
	{
		TargetUn = true;			
	}

	if (TargetUn) {
		if (PosPNJ.x < Target2.x) {
			PosPNJ.x += Speed * DeltaTime;
		}
		else if (PosPNJ.y < Target2.y) {
			PosPNJ.y += Speed * DeltaTime;
		}
	}

	_character->rectangle.setPosition(PosPNJ);
	
	if (NearlyEqual(PosPNJ.x, Target2.x, 5.0f) && NearlyEqual(PosPNJ.y, Target2.y, 5.0f)) 
	{
		EndExecute();
	}
}

void NPCMooveTo::EndExecute()
{
	Parent->OnChildEnd(ENodeState::Success);

}