//
// Created by Youssef on 13/02/2026.
//

#include "traderSale.h"
#include "BehaviorTree.h"
#include <iostream>


traderSale::traderSale()
    : traderSale(nullptr, nullptr)
{
}

traderSale::traderSale(BehaviorTree* Tree, FlowNode* NodeParent)
    : TaskNode(Tree, NodeParent), TimeSpent(0.0f)
{
}

traderSale::~traderSale()
{
}

void traderSale::BeginExecute()
{
    TimeSpent = 0.0f;

    traderBlackBoard* _BlackBoard = static_cast<traderBlackBoard*>(GetBlackBoard());
    if (_BlackBoard != nullptr && _BlackBoard->_trader != nullptr) {
        trader* _trader = _BlackBoard->_trader;

        srand(static_cast<unsigned int>(time(nullptr)));
        int desiredQuantity = 1 + (rand() % 3); // 1, 2 ou 3 baguettes

        int currentStock = _trader->GetBreadStock();
        std::cout << "traderSale: Stock actuel = " << currentStock << " baguettes" << std::endl;

        if (currentStock > 0) {
            int soldQuantity = _trader->SellBread(desiredQuantity);
            std::cout << "traderSale: " << soldQuantity << " baguette(s) vendue(s)" << std::endl;
        }
        else {
            std::cout << "traderSale: Plus de stock disponible!" << std::endl;
        }
    }
}

void traderSale::Tick(float DeltaTime) {
    TaskNode::Tick(DeltaTime);

    TimeSpent += DeltaTime;

    if (TimeSpent > 5.0f)
    {
        EndExecute();
    }
}

void traderSale::EndExecute()
{
    std::cout << "traderSale: Vente terminée" << std::endl;
    Parent->OnChildEnd(ENodeState::Success);
}