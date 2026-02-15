#pragma once
#include "FlowNode.h"
#include "BehaviorTree.h"
#include "TaskNode.h"

class traderSale : public TaskNode {
public:
    traderSale();
    traderSale(BehaviorTree* Tree, FlowNode* NodeParent);
    virtual ~traderSale() override;

    virtual void BeginExecute() override;
    virtual void Tick(float DeltaTime) override;
    virtual void EndExecute() override;
public:

    float TimeSpent;

    Merchant* _merchant;
};
