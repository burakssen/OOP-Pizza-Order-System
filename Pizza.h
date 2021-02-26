/*  Name    : Burak
    Surname : Şen
    ID      : 150170063
    Date    : 26.03.2020
*/

#ifndef _PIZZA
#define _PIZZA

#include "linkedlist.h"

using namespace std;

class Pizza
{
private:
    string name;             //pizza name
    string size;             //pizza size
    string crust_type;       //pizza crust type
    LinkedList *ingredients; //Linkedlist of the ingredients in the pizza

public:
    Pizza();                    //default pizza constructor
    Pizza(string, string, int); //pizza constructor with input
    Pizza(const Pizza &);       //copy contructor of the pizza
    ~Pizza();                   //destructor of the pizza
    string getName();
    string getSize();
    string getCrustType();
    LinkedList *getIngredients();
};

Pizza::Pizza()
{                                        //default constructor of the pizza
    this->ingredients = new LinkedList;  //we create new linkedlist for the pizza
    this->size = "medium";               // we define pizza size medium
    this->ingredients->add("mozarella"); // we add mozarella to ingredients
    this->crust_type = "normal";         //we define crust type normal
}

Pizza::Pizza(string size, string crust_type, int pizza_type)
{                                       // pizza constructor with inputs
    this->ingredients = new LinkedList; //we create new linkedlist for the pizza
    this->size = size;                  //take given size and assign to the pizzas size
    this->crust_type = crust_type;      //take given crust type and assign to the pizzas crust type
    switch (pizza_type)
    { //choose what type of the pizza that will be created by pizza type
    case 1:
        this->name = "Chicken Pizza";        //define pizza name
        this->ingredients->add("mozarella"); //<--- add an ingredient to the pizza
        this->ingredients->add("chicken");   //process the same steps until cases end
        this->ingredients->add("mushroom");
        this->ingredients->add("corn");
        this->ingredients->add("onion");
        this->ingredients->add("tomato");
        break;
    case 2:
        this->name = "Broccoli Pizza";
        this->ingredients->add("mozarella");
        this->ingredients->add("broccoli");
        this->ingredients->add("pepperoni");
        this->ingredients->add("olive");
        this->ingredients->add("corn");
        this->ingredients->add("onion");
        break;
    case 3:
        this->name = "Sausage Pizza";
        this->ingredients->add("mozarella");
        this->ingredients->add("sausage");
        this->ingredients->add("tomato");
        this->ingredients->add("olive");
        this->ingredients->add("mushroom");
        this->ingredients->add("corn");
        break;
    default:
        break;
    }
}

Pizza::Pizza(const Pizza &p1)
{ //copy constructor in this constructor we create a pizza that is a copy of another pizza
    Node *traverse;
    LinkedList *templinkedlist;
    templinkedlist = new LinkedList;      //create copy pizza to linked list
    traverse = p1.ingredients->getHead(); //assign base pizzas head to traverse
    while (traverse)
    {                                                                              //
        cout << traverse->getIndex() << ". " << traverse->getIngredient() << endl; //print ingredients of the pizza one by one
        traverse = traverse->getNext();                                            //
    }
    cout << "Press 0 to save it." << endl;
    this->name = p1.name;                 //assign base pizza's name to copy pizza
    this->size = p1.size;                 //assign base pizza's size to copy pizza
    this->crust_type = p1.crust_type;     // assign base pizza's crust type to copy pizza
    traverse = p1.ingredients->getHead(); //assign base pizzas head to traverse again
    while (traverse)
    {
        templinkedlist->add(traverse->getIngredient()); //add ingredients one by one to linkedlist
        traverse = traverse->getNext();
    }
    this->ingredients = templinkedlist; //assign copy pizza's ingredients
}

string Pizza::getName()
{
    return this->name;
}

string Pizza::getSize()
{
    return this->size;
}

string Pizza::getCrustType()
{
    return this->crust_type;
}

LinkedList *Pizza::getIngredients()
{
    return this->ingredients;
}

Pizza::~Pizza()
{                             //destructor of the pizza
    delete this->ingredients; //we have to delete pizza's ingredients to prevent memory leak
}

#endif