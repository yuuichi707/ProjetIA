//
// Created by Youssef on 14/02/2026.
//

#include "Sequence.h"

Sequence::Sequence() : Sequence(nullptr, nullptr, {}) {
}

Sequence::Sequence(BehaviorTree* Tree, FlowNode* NodeParent, const std::vector<Node*>& NodeChilds)
    : FlowNode(Tree, NodeParent, NodeChilds) {
}

Sequence::~Sequence() {
}

void Sequence::OnChildEnd(ENodeState ChildResult) {
    if (ChildResult == ENodeState::Success) {
        FlowNode::OnChildEnd(ChildResult);

        if (CurrentExecuteChild != nullptr) {
            CurrentExecuteChild->BeginExecute();
        }
        else {
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
