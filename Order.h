/*
    Name    : Burak
    Surname : Şen
    ID      : 150170063
    Date    : 26.03.2020
*/

#ifndef _ORDER
#define _ORDER

#include "pizzalist.h"
#include "drinklist.h"
#include "dnode.h"
#include "pnode.h"
#include <string>

using namespace std;

class Order
{
private:
    string customer_name; // customer name defined
    PizzaList *pizzas;    // pizza list for pizzas in the order
    DrinkList *drinks;    // drink list for drinks in the order

public:
    Order(string, PizzaList &);              //order constructor without drink list
    Order(string, PizzaList &, DrinkList &); //order constructor with drink list
    ~Order();                                //order destructor
    double getPrice();                       //  to calculate the price
    void printDrink();                       //  print drink orders
    void printOrder();                       //  print order
    string getCustomerName();
    PizzaList *getPizzas();
    DrinkList *getDrinks();
};

Order::Order(string customer_name, PizzaList &pizza_list)
{                                        //constructor without drink list
    this->customer_name = customer_name; //assign the object given customer name
    this->pizzas = &pizza_list;          //assign the object given pizza list
    this->drinks = NULL;                 //because there is no drink we assign drink list NULL
}
Order::Order(string customer_name, PizzaList &pizza_list, DrinkList &drink_list)
{                                        //constructor with drink list
    this->customer_name = customer_name; //assign the object given customer name
    this->pizzas = &pizza_list;          //assign the object given pizza list
    this->drinks = &drink_list;          //assign the object given drink list
}

double Order::getPrice()
{                                             //in this function we calculate the order's total price and return the price
    double price = 0.0;                       //define price 0 at the start
    PNode *traversePizza;                     // we define PNode for tracking pizzas from pizza list in the order
    DNode *traverseDrink;                     // we define DNode for tracking drinks from drink list in the order
    traversePizza = this->pizzas->getPHead(); //we start tracking from pizzas assign pizzalist's head to traversePizza
    while (traversePizza)
    { //if there is a pizza
        //in the bottom pizzalist goes one pizza by one and controls their size and multiplies the default price with the amount and calculate the price
        if (traversePizza->getPizza()->getSize() == "small")
        {
            price = price + traversePizza->getAmount() * 15;
        }
        else if (traversePizza->getPizza()->getSize() == "medium")
        {
            price = price + traversePizza->getAmount() * 20;
        }
        else if (traversePizza->getPizza()->getSize() == "big")
        {
            price = price + traversePizza->getAmount() * 25;
        }
        traversePizza = traversePizza->getNext();
    }
    if (this->drinks != NULL)
    {                                             // if there is a drink list we add drink's price to price
        traverseDrink = this->drinks->getDHead(); //we start tracking from drinks assign drinklist's head to traverseDrink
        //in the bottom drinklist goes one drink by one and controls their name and multiplies the default price with the amount and calculate the price
        while (traverseDrink)
        {
            if (traverseDrink->getDrink()->getName() == "cola")
            {
                price = price + traverseDrink->getAmount() * 4;
            }
            else if (traverseDrink->getDrink()->getName() == "soda")
            {
                price = price + traverseDrink->getAmount() * 2;
            }
            else if (traverseDrink->getDrink()->getName() == "ice tea")
            {
                price = price + traverseDrink->getAmount() * 3;
            }
            else if (traverseDrink->getDrink()->getName() == "fruit juice")
            {
                price = price + traverseDrink->getAmount() * 3.5;
            }
            traverseDrink = traverseDrink->getNext();
        }
    }
    return price; //return price of the order
}

void Order::printOrder()
{                                             // in this function we print the order
    PNode *traversePizza;                     //we define a PNode pointer
    traversePizza = this->pizzas->getPHead(); // we assign pizzalist head to traversePizza
    cout << "------------" << endl;
    cout << "Name: " << this->customer_name << endl; //print customer name of the order
    while (traversePizza)
    { //while there is a pizza
        cout << endl;
        cout << traversePizza->getAmount() << "x " << traversePizza->getPizza()->getName() << "(" << traversePizza->getPizza()->getIngredients()->getdata() << ")" << endl; //print amount of the, pizza name, pizza ingredients
        cout << "size: " << traversePizza->getPizza()->getSize() << ", "
             << "crust : " << traversePizza->getPizza()->getCrustType() << endl; //print pizza size, crust type
        traversePizza = traversePizza->getNext();
    }
    cout << endl;
    printDrink(); //print drinks if there is any
    cout << "------------" << endl;
}

void Order::printDrink()
{
    if (this->drinks != NULL)
    { //if there is drinklist
        DNode *traverseDrink;
        traverseDrink = this->drinks->getDHead(); //assgin drinklist hed to DNode pointer
        while (traverseDrink)
        {                                                                                               //while there is a drink
            cout << traverseDrink->getAmount() << "x " << traverseDrink->getDrink()->getName() << ", "; //print drink amount, drink name
            traverseDrink = traverseDrink->getNext();
        }
        cout << endl;
    }
}

Order::~Order()
{                        //destructor of the order class
    delete this->pizzas; //delete pizza list in the order to prevent memory leak
    if (this->drinks != NULL)
    {                        //if there is a drinklist
        delete this->drinks; //delete drinklist in the order to prevent memory leak
    }
}

string Order::getCustomerName()
{
    return this->customer_name;
}

PizzaList *Order::getPizzas()
{
    return this->pizzas;
}
DrinkList *Order::getDrinks()
{
    return this->drinks;
}

#endif