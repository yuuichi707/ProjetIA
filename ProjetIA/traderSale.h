//
// Created by Youssef on 13/02/2026.
//

#ifndef PROJETIA_TRADERSALE_H
#define PROJETIA_TRADERSALE_H

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
    };


#endif //PROJETIA_TRADERSALE_H