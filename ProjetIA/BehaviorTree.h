//
// Created by Youssef on 11/02/2026.
//

 // #ifndef PROJETIA_BEHAVIORTREE_H
 // #define PROJETIA_BEHAVIORTREE_H
 //
 //
 // #pragma once
 // #include <vector>
 //
 // class RootNode;
 // class BaseNode;
 //
 // class Blackboard{
 // public:
 //
 // };


 // class BehaviorTree{
 // public:
 //     BehaviorTree();
 //     BehaviorTree(Blackboard* BB);
 //     virtual ~BehaviorTree();
 //
 //     void BeginExecute();
 //     void Tick(float DeltaTime);
 //
 //     virtual void BuildTree();
 //     void CleanTree();
 //
 //     Blackboard* GetBlackBoard();
 // protected:
 //     Blackboard* InternBlackBoard;
 //     RootNode* Root;
 //     std::vector<BaseNode*> AllSubNodes;
 //      };
 //
 //
 // class TraderBlackBoard : public Blackboard{
 // public:
 //     int PlayerX;
 //     int PlayerY;
 //
 //     int MyPosX;
 //     int MyPosY;
 //
 //     int MyDirX;
 //     int MyDirY;
 //
 //     bool SeePlayer;
 //
 //     int Point1X;
 //     int Point1Y;
 //
 //     int Point2X;
 //     int Point2Y;
 // };
 //
 //
 // class TraderBehaviorTree : public BehaviorTree{
 // public:
 //     TraderBehaviorTree();
 //     TraderBehaviorTree(Blackboard* BB);
 //     virtual ~TraderBehaviorTree();
 //
 //     virtual void BuildTree() override;
 // };
 //
 //
 //
 // #endif //PROJETIA_BEHAVIORTREE_H