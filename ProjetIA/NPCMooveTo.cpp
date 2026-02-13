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
	
	//getposition -> vector2f
	//add speed sur x et y 

	if (PosPNJ.x < Target1.x) {
		PosPNJ.x += Speed * DeltaTime;
	}
	if (PosPNJ.y < Target1.y) {
		PosPNJ.y += Speed * DeltaTime;
	}



	_character->rectangle.setPosition(PosPNJ);
	//il faut vérifier si on est au dela de l'objectif
	//si oui alors
	
	if (NearlyEqual(PosPNJ.x, Target2.x, 5.0f) && NearlyEqual(PosPNJ.y, Target2.y, 5.0f)) 
	{
		EndExecute();
	}
	
	else if (PosPNJ.x > Target1.x && PosPNJ.y > Target1.y) {
		PosPNJ.x += -Speed * DeltaTime;
		PosPNJ.y += -Speed * DeltaTime;
	}
	
}

void NPCMooveTo::EndExecute()
{
	Parent->OnChildEnd(ENodeState::Success);

}


