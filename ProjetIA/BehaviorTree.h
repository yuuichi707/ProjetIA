#pragma once
#include <vector>
#include "Character.h"
#include "trader.h"

class RootNode;
class BaseNode;

class Blackboard {
public:

};


class BehaviorTree {
public:
	BehaviorTree();
	BehaviorTree(Blackboard* BB);
	virtual ~BehaviorTree();

	void BeginExecute();
	void Tick(float DeltaTime);

	virtual void BuildTree();
	void CleanTree();

	Blackboard* GetBlackBoard();
protected:
	Blackboard* InternBlackBoard;
	RootNode* Root;
	std::vector<BaseNode*> AllSubNodes;
};

class Merchant {
public:
    Merchant() : money(1000.0f), rent(200.0f), breadStock(10) {}

    float GetMoney() const { return money; }
    void SetMoney(float newMoney) { money = newMoney; }

    float GetRent() const { return rent; }

    int GetBreadStock() const { return breadStock; }
    void SetBreadStock(int stock) { breadStock = stock; }

    bool Pay(float amount) {
        if (money >= amount) {
            money -= amount;
            return true;
        }
        return false;
    }

    int SellBread(int quantity) {
        int soldQuantity = (quantity <= breadStock) ? quantity : breadStock;
        breadStock -= soldQuantity;
        money += soldQuantity * 2.0f;
        return soldQuantity;
    }

private:
    float money;
    float rent;
    int breadStock;
};



class NPCBlackBoard : public Blackboard {
public:
	NPCBlackBoard() = default;
	NPCBlackBoard(Character* pnj);

	Character* _character;
	/*std::vector<*/
};


class NPCBehaviorTree : public BehaviorTree {
public:
	NPCBehaviorTree();
	NPCBehaviorTree(Blackboard* BB);
	virtual ~NPCBehaviorTree();

	virtual void BuildTree() override;
};

class traderBlackBoard : public Blackboard {
public:
    traderBlackBoard() = default;
    traderBlackBoard(trader* pnj);

    trader* _trader;
    Merchant* _merchant;

};


class traderBehaviorTree : public BehaviorTree {
public:
    traderBehaviorTree();
    traderBehaviorTree(Blackboard* BB);
    virtual ~traderBehaviorTree();

    virtual void BuildTree() override;
};