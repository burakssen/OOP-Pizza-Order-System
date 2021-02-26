/*  Name    : Burak
    Surname : Şen
    ID      : 150170063
    Date    : 26.03.2020
*/

#ifndef _LINKED_LIST
#define _LINKED_LIST
#include "node.h"

using namespace std;

class LinkedList
{
private:
    Node *head; //define a head for linkedlist this is ingredients list

public:
    LinkedList();                     //linkedlist constructor
    ~LinkedList();                    //linkedlist destructor
    void add(string);                 //add ingredients to linkedlist
    void remove(string);              //remove ingredients from the linkedlist
    void removeAllLinkedList(Node &); //remove all ingredients from the linked list
    string getdata();                 //get all ingredients in one string for print purposes
    Node *getHead();
};

LinkedList::LinkedList()
{                      //constructor of the linkedlist
    this->head = NULL; //assign head of the linked list with NULL
}

void LinkedList::add(string data)
{ //in this function we add ingredients one by one to linkedlist
    Node *traverse;
    Node *newnode;
    int i = 2;             //index of the ingredients
    traverse = this->head; //we assign linkedlist's head to traverse
    if (this->head == NULL)
    {                                //if there is no ingredients
        newnode = new Node(1, data); //we create new node with index and ingredients name
        this->head = newnode;        //and newnode becomes head
        return;
    }
    while (traverse->getNext() != NULL)
    {                                   //if there is a head
        i++;                            //we increase the index
        traverse = traverse->getNext(); //traverse pointer goes the end of the list
    }
    newnode = new Node(i, data); //and we create a new node with the index and ingredients name
    traverse->setNext(*newnode); //add newnode the end of the list
}
void LinkedList::remove(string data)
{ //in this function we remove choosen ingredient from linkedlist
    Node *traverse;
    Node *temp;
    traverse = this->head;        //we assign head of the linkedlist to traverse
    temp = this->head->getNext(); //we assign head's next to temp
    if (this->head->getIngredient() == data)
    {                                   //if our ingredients is equal to choosen ingredient that will be removed
        traverse = traverse->getNext(); //we take traverse to traverse next
        delete this->head;              //we delete head
        this->head = traverse;          //and we assign head to traverse
        return;
    }
    while (traverse->getNext()->getIngredient() != data)
    { //if head is not the choosen ingredient we take our pointers until we find  the choosen ingredient
        traverse = traverse->getNext();
        temp = temp->getNext();
    }
    if (traverse->getNext()->getIngredient() == data)
    { //and we take our temp pointer to the next of it
        temp = temp->getNext();
    }
    delete traverse->getNext(); //and we delete the node to prevent the memory leak
    traverse->setNext(*temp);   //and we complete our linkedlist with attaching nodes that splitted from each other
}

string LinkedList::getdata()
{ //this function gets all ingrediens and puts them in one string and return it
    Node *traverse;
    traverse = head; //we assign traverse linkedlist head
    string ingr;
    while (traverse != NULL)
    {                                                   //while there is ingredient
        ingr = ingr + traverse->getIngredient() + ", "; //we add our strings
        traverse = traverse->getNext();
    }
    return ingr; //return string
}

void LinkedList::removeAllLinkedList(Node &temp)
{
    if (temp.getNext() != NULL)
    {                                         //if our node has a next node
        removeAllLinkedList(*temp.getNext()); // we call this function with next node
    }

    //if there is not any next node its broke the recursive loop

    delete &temp; //we delete the node (it is always the last node of the list)
}

LinkedList::~LinkedList()
{                                           //destructor of the linkedlist when we delete linkedlist we have to delete other objects in the linkedlist as well
    this->removeAllLinkedList(*this->head); //we call removealllinkedlist function and remove all of the ingredients
}

Node *LinkedList::getHead()
{
    return this->head;
}
#endif