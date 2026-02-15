//
// Created by Youssef on 14/02/2026.
//

#include "TaskNode.h"
TaskNode::TaskNode() : TaskNode(nullptr, nullptr){
}

TaskNode::TaskNode(BehaviorTree* Tree, FlowNode* NodeParent) : Node(Tree, NodeParent){
}

TaskNode::~TaskNode()
{
}
