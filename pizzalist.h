/*  Name    : Burak
    Surname : Şen
    ID      : 150170063
    Date    : 26.03.2020
*/

#ifndef _PIZZA_LIST
#define _PIZZA_LIST

#include "pnode.h"

using namespace std;

class PizzaList
{
private:
    PNode *PHead; //pizzalist's head

public:
    PizzaList();                         //pizzalist constructor
    ~PizzaList();                        //pizzalist destructor
    void addPizza(Pizza &);              //add pizzas to pizzalist
    static void removeAllPizza(PNode &); //remove all pizzas from the pizzalist
    PNode *getPHead();
};

PizzaList::PizzaList()
{                       //pizza constructor
    this->PHead = NULL; //assign pizzalist's head to NULL to start a pizzalist
}

void PizzaList::addPizza(Pizza &data)
{                    //in this function we add pizzas to pizzalist
    PNode *traverse; //to track pizzalist define PNode pointers
    PNode *tail;
    PNode *newnode;                    //to add new pizzas define PNode pointer
    tail = this->PHead;                //we assign tail pointer to head of the pizzalist
    int amount = 1;                    //when new pizza added amount of the pizza defined 1
    newnode = new PNode(amount, data); //new pizza created and its pointed by newnode pointer
    if (this->PHead == NULL)
    {                          //if there is not a node(pizza) in the start of the pizzalist
        this->PHead = newnode; //we assign the newnode head node of the list
        return;
    }
    traverse = tail->getNext(); //we assign traverse to tail's next
    if (tail->getPizza()->getIngredients()->getdata() == newnode->getPizza()->getIngredients()->getdata())
    {                                           //if there is a pizza that hold's same ingredients at the head of the list
        tail->setAmount(tail->getAmount() + 1); //we increase the amount of the pizza
        delete newnode;                         //and delete the new pizza to prevent the memory leak
        return;
    }
    while (traverse)
    { //while there is a next node
        if (traverse->getPizza()->getIngredients()->getdata() == newnode->getPizza()->getIngredients()->getdata())
        {                                                   //if there is a pizza that hold's same ingredients at the next node
            traverse->setAmount(traverse->getAmount() + 1); //increase next nodes amount by one
            delete newnode;                                 //and delete the new pizza to prevent the memory leak
            return;
        }
        tail = tail->getNext();
        traverse = tail->getNext();
    }
    newnode->setAmount(amount); //if there is no same pizza, amount of the pizza must be one
    tail->setNext(*newnode);    //if there is no same pizza, add the pizza the end of the list
}

void PizzaList::removeAllPizza(PNode &temp)
{ //in this function we delete all of the pizzas from pizzalist
    if (temp.getNext() != NULL)
    {                                    //if our node has a next node
        removeAllPizza(*temp.getNext()); //we call this function with next node
    }

    //after we can't find any next node and if our node is exist
    delete &temp; //we delete the node (it is always the last node of the list)
}

PNode *PizzaList::getPHead()
{
    return this->PHead;
}

PizzaList::~PizzaList()
{ //the destructor of the pizzalist
    if (this->PHead != NULL)
    {                                       //if there is any pizza
        this->removeAllPizza(*this->PHead); //we call removeallpizza function and remove all of the pizzas from pizzalist
    }
}

#endif