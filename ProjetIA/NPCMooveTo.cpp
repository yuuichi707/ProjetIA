#include "NPCMooveTo.h"
#include <iostream>
#include "FlowNode.h"

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
		
		//Position
		Target = { 410, 220 };

		//Character*
		_character = _BlackBoard->_character;
		PosPNJ = _character->rectangle.getPosition();

	}
}

void NPCMooveTo::Tick(float DeltaTime)
{
	TaskNode::Tick(DeltaTime);

	if (PosPNJ.x < Target.x) {
		PosPNJ.x += Speed * DeltaTime;
	}
	else if (PosPNJ.y > Target.y) {
		PosPNJ.y -= Speed * DeltaTime;
	}

	_character->rectangle.setPosition(PosPNJ);
	
	if (NearlyEqual(PosPNJ.x, Target.x, 10.0f) && NearlyEqual(PosPNJ.y, Target.y, 10.0f))
	{
		std::cout << "gdfgh";
		EndExecute();
	}
}

void NPCMooveTo::EndExecute()
{
	Parent->OnChildEnd(ENodeState::Success);
}