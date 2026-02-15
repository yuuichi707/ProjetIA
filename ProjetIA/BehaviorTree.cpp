//
// Created by Youssef on 11/02/2026.
//

#include "BehaviorTree.h"
#include "FallBack.h"
#include "Node.h"
#include "Sequence.h"
#include "traderPay.h"
#include "traderSale.h"

BehaviorTree::BehaviorTree() : BehaviorTree(nullptr) {

}

BehaviorTree::BehaviorTree(Blackboard* BB) : InternBlackBoard(BB), Root(nullptr) {

}

BehaviorTree::~BehaviorTree() {
    CleanTree();
}

void BehaviorTree::BeginExecute() {
    if (Root != nullptr) {
        Root->BeginExecute();
    }
}

void BehaviorTree::Tick(float DeltaTime) {
    if (Root != nullptr) {
        Root->Tick(DeltaTime);
    }
}

void BehaviorTree::BuildTree() {
    Root = new RootNode(this, nullptr);
}

void BehaviorTree::CleanTree() {
    if (Root != nullptr) {
        delete Root;
        Root = nullptr;
    }

    for (auto* Node : AllSubNodes) {
        delete Node;
    }
    AllSubNodes.clear();
}

Blackboard* BehaviorTree::GetBlackBoard()
{
    return InternBlackBoard;
}

traderBlackBoard::traderBlackBoard(trader* pnj) : _trader(pnj) {
}

traderBehaviorTree::traderBehaviorTree() : traderBehaviorTree(nullptr) {
}

traderBehaviorTree::traderBehaviorTree(Blackboard* BB) : BehaviorTree(BB) {
}

traderBehaviorTree::~traderBehaviorTree() {
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