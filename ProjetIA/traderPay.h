#pragma once
#include <SFML/System/Vector2.hpp>
#include "TaskNode.h"
#include "BehaviorTree.h"


class traderPay : public TaskNode
{
public:
    traderPay();
    traderPay(traderBehaviorTree* Tree, FlowNode* NodeParent);
    virtual ~traderPay() override;

    virtual void BeginExecute() override;
    virtual void Tick(float DeltaTime) override;
    virtual void EndExecute() override;

    

private:

    float money = _merchant->GetMoney();
    float rent = _merchant->GetRent();

    Merchant* _merchant;
};