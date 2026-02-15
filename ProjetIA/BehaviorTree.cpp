#include "BehaviorTree.h"
#include "traderPay.h"
#include "traderSale.h"
#include "FallBack.h"
#include "Node.h"
#include "Sequence.h"
#include "NPCMooveTo.h"
#include "NPCBuy.h"
#include "NPCQuit.h"

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

NPCBehaviorTree::NPCBehaviorTree() : NPCBehaviorTree(nullptr) {
}

NPCBehaviorTree::NPCBehaviorTree(Blackboard* BB) : BehaviorTree(BB) {
}

NPCBehaviorTree::~NPCBehaviorTree() {
}

void NPCBehaviorTree::BuildTree() {
	BehaviorTree::BuildTree();

	FallBack* FallBack1 = new FallBack(this, nullptr, {});
	Root->Child = FallBack1;

	Sequence* Sequence1 = new Sequence(this, FallBack1, {});
	FallBack1->AddChild(Sequence1);

	NPCMooveTo* Task1 = new NPCMooveTo(this, Sequence1);
	Sequence1->AddChild(Task1);
	NPCBuy* Task2 = new NPCBuy(this, Sequence1);
	Sequence1->AddChild(Task2);
	NPCQuit* Task3 = new NPCQuit(this, Sequence1);
	Sequence1->AddChild(Task3);


	AllSubNodes.push_back(Sequence1);
	AllSubNodes.push_back(FallBack1);
	AllSubNodes.push_back(Task1);
	AllSubNodes.push_back(Task2);
	AllSubNodes.push_back(Task3);
}

traderBehaviorTree::traderBehaviorTree()
{
}

traderBehaviorTree::traderBehaviorTree(Blackboard* BB)
{
}

traderBehaviorTree::~traderBehaviorTree()
{
}

void traderBehaviorTree::BuildTree() {
	BehaviorTree::BuildTree();

	FallBack* FallBack1 = new FallBack(this, nullptr, {});
	Root->Child = FallBack1;

	Sequence* Sequence1 = new Sequence(this, FallBack1, {});
	FallBack1->AddChild(Sequence1);

	traderPay* Task1 = new traderPay(this, Sequence1);
	Sequence1->AddChild(Task1);

	traderSale* Task2 = new traderSale(this, Sequence1);
	Sequence1->AddChild(Task2);

	AllSubNodes.push_back(FallBack1);
	AllSubNodes.push_back(Sequence1);
	AllSubNodes.push_back(Task1);
	AllSubNodes.push_back(Task2);
}




NPCBlackBoard::NPCBlackBoard(Character* pnj) {
	_character = pnj;
}

traderBlackBoard::traderBlackBoard(trader* pnj)
{
}
