/*  Name    : Burak
    Surname : Şen
    ID      : 150170063
    Date    : 26.03.2020
*/

#ifndef _NODE
#define _NODE
#include <string>

using namespace std;

class Node
{
private:
    int index;   //index of the ingredient
    string data; //name of the ingredient
    Node *next;  //next of the node

public:
    Node(int, string); //Node constructor
    ~Node();           //Node destructor
    int getIndex();
    string getIngredient();
    Node *getNext();
    void setNext(Node &);
};

Node::Node(int index, string data)
{                        //Node constructor assign given values
    this->index = index; //assign index
    this->data = data;   //assign drink
    this->next = NULL;   //assign node's next to NULL
}

int Node::getIndex()
{
    return this->index;
}

string Node::getIngredient()
{
    return this->data;
}

Node *Node::getNext()
{
    return this->next;
}

void Node::setNext(Node &next)
{
    this->next = &next;
}

Node::~Node() {} //destructor of the Node, there is noting in it because there is not a variable with allocated memory

#endif