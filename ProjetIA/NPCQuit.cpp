#include "NPCQuit.h"
#include "FlowNode.h"
#include "TaskNode.h"
#include <iostream>

NPCQuit::NPCQuit() 
	: NPCQuit(nullptr, nullptr)
{

}

NPCQuit::NPCQuit(BehaviorTree* Tree, FlowNode* NodeParent) 
	: TaskNode(Tree, NodeParent)
{

}

void NPCQuit::BeginExecute()
{
	NPCBlackBoard* _BlackBoard = static_cast<NPCBlackBoard*>(GetBlackBoard());

	if (_BlackBoard != nullptr) {

		_character = _BlackBoard->_character;
		PosPNJ = _character->rectangle.getPosition();

		//Position
		Target = { 1430, 350 };

	}
}

void NPCQuit::Tick(float DeltaTime)
{
	TaskNode::Tick(DeltaTime);

	std::cout << "start to quit";
	if (PosPNJ.y < Target.y) {
		PosPNJ.y += Speed * DeltaTime;
	}

	else if (PosPNJ.x < Target.x) {
		PosPNJ.x += Speed * DeltaTime;
	}
	

	_character->rectangle.setPosition(PosPNJ);


	if (NearlyEqual(PosPNJ.x, Target.x, 10.0f) && NearlyEqual(PosPNJ.y, Target.y, 10.0f))
	{
		EndExecute();
	}
	else if (PosPNJ.x > Target.x && PosPNJ.y > Target.y) {
		PosPNJ.x += -Speed * DeltaTime;
		PosPNJ.y += -Speed * DeltaTime;
	}
}

void NPCQuit::EndExecute()
{
	
}



