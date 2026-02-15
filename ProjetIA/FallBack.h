//
// Created by Youssef on 13/02/2026.
//

#ifndef PROJETIA_FALLBACK_H
#define PROJETIA_FALLBACK_H


#pragma once

#include "FlowNode.h"

class FallBack : public FlowNode {
public:
    FallBack();
    FallBack(BehaviorTree* Tree, FlowNode* NodeParent, const std::vector<Node*>& NodeChilds);
    virtual ~FallBack() override;

    virtual void OnChildEnd(ENodeState ChildResult) override;
};



#endif //PROJETIA_FALLBACK_H