//
// Created by Youssef on 14/02/2026.
//

#include "traderPay.h"
#include <iostream>
#include "FlowNode.h"

traderPay::traderPay()
    : traderPay(nullptr, nullptr)
{
}

traderPay::traderPay(traderBehaviorTree* Tree, FlowNode* NodeParent)
    : TaskNode(Tree, NodeParent), Speed(500.0f), NPCTargetX(0.0f), NPCTargetY(0.0f), DotProductResult(0.0f)
{
}

traderPay::~traderPay()
{
}

void traderPay::BeginExecute()
{
    traderBlackBoard* _BlackBoard = static_cast<traderBlackBoard*>(GetBlackBoard());
    if (_BlackBoard != nullptr && _BlackBoard->_trader != nullptr) {
        _trader = _BlackBoard->_trader;

        std::cout << "traderPay: Début du paiement du loyer" << std::endl;
    }
}

void traderPay::Tick(float DeltaTime)
{
    TaskNode::Tick(DeltaTime);

    if (_trader == nullptr) {
        EndExecute();
        return;
    }

     if (money >= rent) {
         _trader->Pay(rent);
         std::cout << "traderPay: Loyer payé" << std::endl;
         EndExecute();
     } else {
         std::cout << "traderPay: Pas assez d'argent pour le loyer" << std::endl;
         Parent->OnChildEnd(ENodeState::Failure);
     }
}

void traderPay::EndExecute()
{
    std::cout << "traderPay: Fin du paiement" << std::endl;
    Parent->OnChildEnd(ENodeState::Success);
}