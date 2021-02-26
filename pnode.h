/*  Name    : Burak
    Surname : Şen
    ID      : 150170063
    Date    : 26.03.2020
*/

#ifndef _PIZZA_NODE
#define _PIZZA_NODE

#include "Pizza.h"

using namespace std;

class Pizza;

class PNode
{
private:
    int amount;  //amount of the pizza
    Pizza *data; //define a pizza
    PNode *next; //PNode's next

public:
    PNode(int, Pizza &); //constructor of the PNode
    ~PNode();            //destructor of the PNode
    int getAmount();
    Pizza *getPizza();
    PNode *getNext();
    void setAmount(int);
    void setNext(PNode &);
};

PNode::PNode(int amount, Pizza &data)
{                          //PNode constructor assign given values
    this->next = NULL;     //assign next of the node to NULL
    this->amount = amount; //assign amount of the pizza
    this->data = &data;    //assign pizza
}

int PNode::getAmount()
{
    return this->amount;
}

Pizza *PNode::getPizza()
{
    return this->data;
}

PNode *PNode::getNext()
{
    return this->next;
}

void PNode::setAmount(int amount)
{
    this->amount = amount;
}

void PNode::setNext(PNode &next)
{
    this->next = &next;
}

PNode::~PNode()
{                      //destructor of the DNode
    delete this->data; //delete Pizza to prevent memory leak
}

#endif