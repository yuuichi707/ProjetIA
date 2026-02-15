#pragma once
#include <SFML/System/Vector2.hpp>
#include "TaskNode.h"
#include "BehaviorTree.h"
#include "Character.h"

class NPCMooveTo : public TaskNode
{
public:
	NPCMooveTo();
	NPCMooveTo(NPCBehaviorTree* Tree, FlowNode* NodeParent);
	virtual ~NPCMooveTo() override;

	virtual void BeginExecute() override;
	virtual void Tick(float DeltaTime) override;
	virtual void EndExecute() override;

	template<class T>
	bool NearlyEqual(const T& A, const T& B, const T& Tolerance) {
		return std::abs(A - B) < Tolerance;
	}

private:
	sf::Vector2f Target;
	sf::Vector2f PosPNJ;

	Character* _character;

	float Speed = 50000;
};

