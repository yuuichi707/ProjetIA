#include "NPCMooveTo.h"
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
		Target = { 1440, 900 };

		//Character*
		_character = _BlackBoard->_character;
		PosPNJ = _character->rectangle.getPosition();

		bool Arrived = false;
	}
}

void NPCMooveTo::Tick(float DeltaTime)
{
	TaskNode::Tick(DeltaTime);
	

	//getposition -> vector2f
	//add speed sur x et y 

	if (PosPNJ.x < Target.x) {
		PosPNJ.x += Speed * DeltaTime;
	}
	if (PosPNJ.y < Target.y) {
		PosPNJ.y += Speed * DeltaTime;
	}

	_character->rectangle.setPosition(PosPNJ);
	//il faut vérifier si on est au dela de l'objectif
	//si oui alors
	if (NearlyEqual(PosPNJ.x, Target.x, 50.0f) && NearlyEqual(PosPNJ.y, Target.y, 50.0f))
	{
		bool Arrived = true;
		EndExecute();
	}
	else if (PosPNJ.x > Target.x && PosPNJ.y > Target.y) {
		PosPNJ.x += -Speed * DeltaTime;
		PosPNJ.y += -Speed * DeltaTime;
	}

	
}

void NPCMooveTo::EndExecute()
{
	if (Arrived == true) {
		Parent->OnChildEnd(ENodeState::Success);
	}
}


