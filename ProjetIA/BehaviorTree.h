#pragma once
#include <vector>

class RootNode;
class BaseNode;

class Blackboard {
public:

};


class BehaviorTree {
public:
	BehaviorTree();
	BehaviorTree(Blackboard* BB);
	virtual ~BehaviorTree();

	void BeginExecute();
	void Tick(float DeltaTime);

	virtual void BuildTree();
	void CleanTree();

	Blackboard* GetBlackBoard();
protected:
	Blackboard* InternBlackBoard;
	RootNode* Root;
	std::vector<BaseNode*> AllSubNodes;
};


class NPCBlackBoard : public Blackboard {
public:
	float NPCx;
	float NPCy;

	float MarchantX;
	float MarchantY;

};


class NPCBehaviorTree : public BehaviorTree {
public:
	NPCBehaviorTree();
	NPCBehaviorTree(Blackboard* BB);
	virtual ~NPCBehaviorTree();

	virtual void BuildTree() override;
};
