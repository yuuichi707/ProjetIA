#include "BehaviorTree.h"

#include "FallBack.h"
#include "Node.h"
#include "SeePlayerTask.h"
#include "Sequence.h"

BehaviorTree::BehaviorTree() : BehaviorTree(nullptr) {

}

BehaviorTree::BehaviorTree(Blackboard* BB) : InternBlackBoard(BB) {

}

BehaviorTree::~BehaviorTree() {

}

void BehaviorTree::BeginExecute() {
	Root->BeginExecute();
}

void BehaviorTree::Tick(float DeltaTime) {
	Root->Tick(DeltaTime);
}

void BehaviorTree::BuildTree() {
	Root = new RootNode();
	AllSubNodes.push_back(Root);
}

void BehaviorTree::CleanTree() {
	for (auto Node : AllSubNodes) {
		delete Node;
		Node = nullptr;
	}
	AllSubNodes.clear();
}

Blackboard* BehaviorTree::GetBlackBoard()
{
	return InternBlackBoard;
}

EnnemyBehaviorTree::EnnemyBehaviorTree() : EnnemyBehaviorTree(nullptr) {
}

EnnemyBehaviorTree::EnnemyBehaviorTree(Blackboard* BB) : BehaviorTree(BB) {
}

EnnemyBehaviorTree::~EnnemyBehaviorTree() {
}

void EnnemyBehaviorTree::BuildTree() {
	BehaviorTree::BuildTree();

	FallBack* FallBack1 = new FallBack(this, nullptr, {});
	Root->Child = FallBack1;

	Sequence* Sequence1 = new Sequence(this, FallBack1, {});
	FallBack1->AddChild(Sequence1);

	AllSubNodes.push_back(Sequence1);
	AllSubNodes.push_back(FallBack1);
}
