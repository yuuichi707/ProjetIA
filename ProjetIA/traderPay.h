//
// Created by Youssef on 14/02/2026.
//

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

    template<class T>
    bool NearlyEqual(const T& A, const T& B, const T& Tolerance) {
        return std::abs(A - B) < Tolerance;
    }

private:
    sf::Vector2f Target1;
    sf::Vector2f Target2;
    sf::Vector2f PosPNJ;

    float money = _trader->GetMoney();
    float rent = _trader->GetRent();

    float NPCTargetX;
    float NPCTargetY;

    trader* _trader;

    float DotProductResult;
    float Speed;
};
