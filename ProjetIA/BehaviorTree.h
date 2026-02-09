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


class EnnemiBlackBoard : public Blackboard {
public:

};


class EnnemyBehaviorTree : public BehaviorTree {
public:
	EnnemyBehaviorTree();
	EnnemyBehaviorTree(Blackboard* BB);
	virtual ~EnnemyBehaviorTree();

	virtual void BuildTree() override;
};
