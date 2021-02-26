/*  Name    : Burak
    Surname : Şen
    ID      : 150170063
    Date    : 26.03.2020
*/

#ifndef _ORDER_NODE
#define _ORDER_NODE

#include "Order.h"

using namespace std;

class ONode
{
private:
    Order *data; //define order
    ONode *next; //ONode's next

public:
    ONode(Order &); //order constructor
    ~ONode();       //order destructor
    Order *getOrder();
    void setOrder(Order &);
    void setNext(ONode &);
    ONode *getNext();
};

ONode::ONode(Order &data)
{                       //order constructor assign given values
    this->next = NULL;  //assign ONode's next to NULL
    this->data = &data; //assign order
}
ONode::~ONode()
{                      //destructor of the ONode
    delete this->data; //delete Pizza to prevent memory leak
}

Order *ONode::getOrder()
{
    return this->data;
}

void ONode::setOrder(Order &data)
{
    this->data = &data;
}

ONode *ONode::getNext()
{
    return this->next;
}

void ONode::setNext(ONode &next)
{
    this->next = &next;
}

#endif