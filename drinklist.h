/*  Name    : Burak
    Surname : Şen
    ID      : 150170063
    Date    : 26.03.2020
*/

#ifndef _DRINK_LIST
#define _DRINK_LIST

#include "dnode.h"

using namespace std;

class DrinkList
{
private:
    DNode *DHead; //head of the drinklist

public:
    DrinkList();                  //constructor of the drinklist
    ~DrinkList();                 //destructor of the drinklist
    void addDrink(Drink &);       //add drink to drinklist
    void removeAllDrink(DNode &); //remove all drinks from the drinklist
    DNode *getDHead();
};

DrinkList::DrinkList()
{                       //constroctor of thr drinklist
    this->DHead = NULL; //assign drinklist's head to NULL to start a drinklist
}

void DrinkList::addDrink(Drink &data)
{                    //in this function we add drinks to the drinklist
    DNode *traverse; //to track drinklist define DNode pointers
    DNode *tail;
    DNode *newnode;                    //to add new drinks define DNode pointer
    tail = DHead;                      //we assign tail pointer to head of the drinklist
    int amount = 1;                    //when new drink added amount of the drink defined 1
    newnode = new DNode(amount, data); //new drink created and it is pointed by newnode pointer
    if (DHead == NULL)
    {                    //if there is not a node(drink) in the start of the drinklist
        DHead = newnode; //we assign the newnode head node of the list
        return;
    }
    traverse = tail->getNext(); //we assign traverse to tail's next
    if (tail->getDrink()->getName() == newnode->getDrink()->getName())
    {                                           //if there is a drink that hold's same name at the head of the list
        tail->setAmount(tail->getAmount() + 1); //we increase the amount of the drink
        delete newnode;                         //and delete the new drink to prevent the memory leak
        return;
    }
    while (traverse)
    { //while there is a next node
        if (traverse->getDrink()->getName() == newnode->getDrink()->getName())
        {                                                   //if there is a drink that hold's same name at the next node
            traverse->setAmount(traverse->getAmount() + 1); //increase next nodes amount by one
            delete newnode;                                 //and delete the new drink to prevent the memory leak
            return;
        }
        tail = tail->getNext();
        traverse = tail->getNext();
    }
    newnode->setAmount(amount); //if there is no same drink, amount of the drink must be one
    tail->setNext(*newnode);    //if there is no same drink, add the drink the end of the list
}
void DrinkList::removeAllDrink(DNode &temp)
{ //in this function we delete all of the drinks from drinklist
    if (temp.getNext() != NULL)
    {                                    //if our node has a next node
        removeAllDrink(*temp.getNext()); //we call this function with next node
    }

    //after we can't find any next node and if our node is exist
    delete &temp; //we delete the node (it is always the last node of the list)
}

DrinkList::~DrinkList()
{ //the destructor of the pizzalist
    if (this->DHead != NULL)
    {                                       //if our list is not empty
        this->removeAllDrink(*this->DHead); //we call removealldrink function and remove all of the drinks
    }
}

DNode *DrinkList::getDHead()
{
    return this->DHead;
}
#endif