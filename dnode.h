/*  Name    : Burak
    Surname : Şen
    ID      : 150170063
    Date    : 26.03.2020
*/

#ifndef _DRINK_NODE
#define _DRINK_NODE

#include "Drink.h"

using namespace std;

class Drink;

class DNode
{
private:
    int amount;  //amount of the drink
    Drink *data; //define a drink in the DNode
    DNode *next; //DNode next

public:
    DNode(int, Drink &); //DNode constructor
    ~DNode();            //DNOde destructor
    int getAmount();
    Drink *getDrink();
    DNode *getNext();
    void setAmount(int);
    void setDrink(Drink &);
    void setNext(DNode &);
};

DNode::DNode(int amount, Drink &data)
{                          //DNode constructor we assign given values
    this->data = &data;    //assign drink
    this->amount = amount; //assign amount of the drink
    this->next = NULL;     //assign next of the DNode to NULL
}

DNode::~DNode()
{                      //destructor of the DNode
    delete this->data; //delete Drink from DNode to prevent memory leak
}

int DNode::getAmount()
{
    return this->amount;
}
Drink *DNode::getDrink()
{
    return this->data;
}
DNode *DNode::getNext()
{
    return this->next;
}

void DNode::setAmount(int amount)
{
    this->amount = amount;
}

void DNode::setDrink(Drink &data)
{
    this->data = &data;
}

void DNode::setNext(DNode &next)
{
    this->next = &next;
}

#endif