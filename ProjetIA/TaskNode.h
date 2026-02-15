//
// Created by Youssef on 14/02/2026.
//

#pragma once
#include "Node.h"

class TaskNode : public Node{
public:
    TaskNode();
    TaskNode(BehaviorTree* Tree, FlowNode* NodeParent);
    virtual ~TaskNode() override;
};