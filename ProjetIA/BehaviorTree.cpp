//
// Created by Youssef on 11/02/2026.
//

// #include "BehaviorTree.h"
//
// #include "FallBack.h"
// #include "Node.h"
// #include "SeePlayerTask.h"
// #include "Sequence.h"
//
// BehaviorTree::BehaviorTree() : BehaviorTree(nullptr){
//
// }
//
// BehaviorTree::BehaviorTree(Blackboard* BB) : InternBlackBoard(BB){
//
// }
//
// BehaviorTree::~BehaviorTree(){
//
// }
//
// void BehaviorTree::BeginExecute(){
//     Root->BeginExecute();
// }
//
// void BehaviorTree::Tick(float DeltaTime){
//     Root->Tick(DeltaTime);
// }
//
// void BehaviorTree::BuildTree(){
//     Root = new RootNode();
//     AllSubNodes.push_back(Root);
// }
//
// void BehaviorTree::CleanTree(){
//     for (auto Node : AllSubNodes){
//         delete Node;
//         Node = nullptr;
//     }
//     AllSubNodes.clear();
// }
//
// Blackboard* BehaviorTree::GetBlackBoard()
// {
//     return InternBlackBoard;
// }
//
// TraderBehaviorTree::TraderBehaviorTree() : TraderBehaviorTree(nullptr){
// }

// TraderBehaviorTree::TraderBehaviorTree(Blackboard* BB) : BehaviorTree(BB){
// }
//
// TraderBehaviorTree::~TraderBehaviorTree(){
// }