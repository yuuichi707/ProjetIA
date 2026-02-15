//
// Created by Youssef on 13/02/2026.
//

#include "FallBack.h"

FallBack::FallBack() : FallBack(nullptr, nullptr, {}) {
}

FallBack::FallBack(BehaviorTree* Tree, FlowNode* NodeParent, const std::vector<Node*>& NodeChilds)
    : FlowNode(Tree, NodeParent, NodeChilds) {
}

FallBack::~FallBack() {
}

void FallBack::OnChildEnd(ENodeState ChildResult) {
    if (ChildResult == ENodeState::Success) {
        if (Parent != nullptr) {
            Parent->OnChildEnd(ENodeState::Success);
        }
        else {
            CurrentExecuteChild = Childs.empty() ? nullptr : Childs[0];
            if (CurrentExecuteChild != nullptr) {
                CurrentExecuteChild->BeginExecute();
            }
        }
    }
    else {
        FlowNode::OnChildEnd(ChildResult);

        if (CurrentExecuteChild != nullptr) {
            CurrentExecuteChild->BeginExecute();
        }
        else {
            if (Parent != nullptr) {
                Parent->OnChildEnd(ENodeState::Failure);
            }
            else {
                CurrentExecuteChild = Childs.empty() ? nullptr : Childs[0];
                if (CurrentExecuteChild != nullptr) {
                    CurrentExecuteChild->BeginExecute();
                }
            }
        }
    }
}
