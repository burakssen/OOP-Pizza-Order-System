/*  Name    : Burak
    Surname : Şen
    ID      : 150170063
    Date    : 26.03.2020
*/

#ifndef _ORDER_LIST
#define _ORDER_LIST

#include "onode.h"
#include <string.h>
#include <cstdlib>

using namespace std;

bool isNumber(string data);

class OrderList
{
private:
    int order_num; //number of orders
    ONode *OHead;  //Order list head

public:
    OrderList();                         //  constructor of the order list
    ~OrderList();                        //  destructor of the order list
    void takeOrder();                    //  for taking orders
    void addOrder(Order &);              //  this function adds orders to order list
    void listOrders();                   //  this function displays all orders
    void deliverOrders();                //  this function deliver the chosen order
    void removeOrder(string);            //  this function removes the delivered order
    static void removeAllOrder(ONode &); //  this function
};

OrderList::OrderList()
{                        //  constructor of the order list
    this->order_num = 0; //  number of orders assign to 0
    this->OHead = NULL;  //  orderlist's head assign to NULL to create list of orders
}

void OrderList::takeOrder()
{
    ONode *traverseOrder;
    Node *traverse;               //  for deleting pizzas ingrediets
    PizzaList *pizza_list;        //  for order create pizzalist pointer
    DrinkList *drink_list;        //  for order create drinklist pointer
    pizza_list = new PizzaList(); //  create new pizzalist
    drink_list = new DrinkList(); //  create new drinklist
    Drink *drink_ptr;             //  for order create drink pointer
    Pizza *pizza_copy_ptr;        //  for pizzalist create pizza pointer
    Order *order_ptr;             //  for orderlist create order pointer
    string customer_name;         //  for order define customer name
    string pizza_type = "4";      //  for choosing pizza type
    string drinkOption = "1";     //  for choosing drink
    string amount = "-1";         //  for amount of pizzzas
    string item_index = "1";      //  for choosing which of the ingredients will be removed
    string drink_name;
    string pizza_size;
    string crust_type;
    bool removed = false;

    cout << endl
         << "Pizza Menu" << endl;
    cout << "1. Chicken Pizza: mozarella, chicken, mushroom, corn, onion, tomato\n"
            "2. Broccoli Pizza: mozarella, broccoli, pepperoni, olive, corn, onion\n"
            "3. Sausage Pizza: mozarella, sausage, tomato, olive, mushroom, corn"
         << endl;
    cout << "0. Back to main menu" << endl;
    while (pizza_type != "0" && pizza_type != "1" && pizza_type != "2" && pizza_type != "3")
    {                      //while pizza type is not a valid value it shows that
        cin >> pizza_type; //our value is not correct and ask a pizza type again
        if (pizza_type != "0" && pizza_type != "1" && pizza_type != "2" && pizza_type != "3")
        {
            cout << endl;
            cout << "Please enter a valid input" << endl;
        }
    }
    cout << endl;
    if (pizza_type == "0")
    {
        //before returning main menu we have to delete created drinklist and pizzalist to prevent memory loss
        delete pizza_list;
        delete drink_list;
        return;
    }
    cout << "Select size: small (15 TL), medium (20 TL), big (25 TL)" << endl;
    while (pizza_size != "small" && pizza_size != "medium" && pizza_size != "big")
    {                      //while pizza size is not a valid value it shows that
        cin >> pizza_size; //our value is not correct and ask a pizza size again
        if (pizza_size != "small" && pizza_size != "medium" && pizza_size != "big")
        {
            cout << endl;
            cout << "Please enter a valid size" << endl;
        }
    }
    cout << endl;
    cout << "Select crust type: thin, normal, thick" << endl;
    while (crust_type != "thin" && crust_type != "normal" && crust_type != "thick")
    {                      //while crust type is not a valid value it shows that
        cin >> crust_type; //our value is not correct and ask a crust type again
        if (crust_type != "thin" && crust_type != "normal" && crust_type != "thick")
        {
            cout << endl;
            cout << "Please enter a valid crust type" << endl;
        }
    }
    cout << endl;
    int t_amount;
    cout << "Enter the amount: ";
    t_amount = atoi(amount.c_str());
    while (t_amount < 0 || t_amount > 25)
    {                  //while pizza amount is not a valid value it shows that
        cin >> amount; //our value is not correct and ask a pizza amount again
        if (isNumber(amount) == true)
        {
            t_amount = atoi(amount.c_str());
            if (t_amount < 0)
            {
                cout << endl;
                cout << "Please enter a valid amount: ";
            }
            else if (t_amount > 25)
            {
                cout << endl;
                cout << "You can't order " << amount << " pizzas at the same time, it is out of range." << endl;
                cout << "Please enter a valid amount: ";
            }
        }
        else
        {
            cout << endl;
            cout << "Please enter a valid amount: ";
        }
    }
    cout << endl;
    Pizza *pizza_ptr;                                                        //create a pizza pointer for copying
    pizza_ptr = new Pizza(pizza_size, crust_type, atoi(pizza_type.c_str())); //create a new pizza with pizza size, crust type and pizza type
    if (t_amount > 1)
    { // if pizza amount is bigger than one
        for (int i = 0; i < t_amount; i++)
        { //in this for loop we will create as many as given amount of pizzas
            cout << "Please enter the number of the ingredient you want to remove from your " << i + 1 << ". pizza." << endl;
            pizza_copy_ptr = new Pizza(*pizza_ptr);                 // we create a new copy of the first created pizza
            traverse = pizza_copy_ptr->getIngredients()->getHead(); // we assign the head of the ingredients of pizza_copy_ptr
            while (item_index != "0")
            {
                cin >> item_index; // we choose which ingredients will be removed
                removed = false;
                while (traverse && item_index != "0")
                { // if in the linkedlist there is 1any ingredient and if item index is not 0
                    if (traverse->getIndex() == atoi(item_index.c_str()))
                    {                                                                        // if choosen index and ingredient index are equal
                        pizza_copy_ptr->getIngredients()->remove(traverse->getIngredient()); //we remove the ingredient
                        removed = true;
                        break;
                    }
                    traverse = traverse->getNext();
                }
                if (removed == false)
                {
                    cout << "Please Enter a valid input" << endl;
                }
                traverse = pizza_copy_ptr->getIngredients()->getHead(); // if we remove the ingredient we had to return our pointer to the head of the linkedlist to ask again which one of the ingredients will be removed
            }
            item_index = "1";                      // to apply the same procedures for other pizzas we set item index to 1
            pizza_list->addPizza(*pizza_copy_ptr); //we add our pizzas to pizza list one by one
            cout << endl;
        }
    }
    else if (t_amount == 1)
    { // if amount of pizza is one we will apply same procedure but just one time
        pizza_copy_ptr = new Pizza(*pizza_ptr);
        traverse = pizza_copy_ptr->getIngredients()->getHead();
        while (item_index != "0")
        {
            cin >> item_index;
            while (traverse && item_index != "0")
            {
                if (traverse->getIndex() == atoi(item_index.c_str()))
                {
                    pizza_copy_ptr->getIngredients()->remove(traverse->getIngredient());
                    break;
                }
                traverse = traverse->getNext();
            }
            traverse = pizza_copy_ptr->getIngredients()->getHead();
        }
        item_index = "1";
        pizza_list->addPizza(*pizza_copy_ptr);
        cout << endl;
    }

    delete pizza_ptr; //we had to delete the base pizza because of the memory leak

    cout << "Please choose a drink:" << endl
         << endl
         << "0. no drink" << endl
         << "1. cola 4 TL" << endl
         << "2. soda 2 TL" << endl
         << "3. ice tea 3 TL" << endl
         << "4. fruit juice 3.5 TL" << endl
         << "Press -1 for save your order" << endl;
    while (drinkOption != "-1")
    {
        cin >> drinkOption; //we choose a drink and set drink_name with choosen value
        if (drinkOption == "1")
        {
            drink_name = "cola";
        }
        else if (drinkOption == "2")
        {
            drink_name = "soda";
        }
        else if (drinkOption == "3")
        {
            drink_name = "ice tea";
        }
        else if (drinkOption == "4")
        {
            drink_name = "fruit juice";
        }
        else if (drinkOption == "-1" || drinkOption == "0") //if drink option is 0 or -1 we break the loop
        {
            break;
        }
        else
        {
            cout << endl
                 << "Please Enter a valid input" << endl;
            continue;
        }
        if (drinkOption != "0" && drinkOption != "-1")
        {                                      //if drinkOption is not 0 or -1
            drink_ptr = new Drink(drink_name); // we will create a new Drink opject with choosen drink_name
            drink_list->addDrink(*drink_ptr);  // and we will add that to drinklist
        }
    }
    cout << endl;
    cout << "Please enter your name:" << endl;
    traverseOrder = this->OHead;
    if (this->OHead != NULL)
    {
        bool customer_name_check = false; //if there is a customer named given name
        while (!customer_name_check)
        {                         //while customer name is not found
            cin >> customer_name; //take customer name
            while (traverseOrder && customer_name != "0")
            { //while order is exist and customer name is not 0
                if (customer_name == traverseOrder->getOrder()->getCustomerName())
                {                                //if customer name is equal one of the orders
                    customer_name_check = false; //customer check is false if customer check is false than our loop continue
                    break;
                }
                customer_name_check = true; //and if our loop comes to end because of pointer comes the en of the order list we couldn't find same name in the orderlist and we break the loop with that name
                traverseOrder = traverseOrder->getNext();
            }
            traverseOrder = this->OHead;
            if (customer_name == "0")
            {                      //if customer wants to return to main menu press 0 and return
                delete drink_list; //beacuse customer didn't save his or hers order we have to delete drink_list and pizza_list
                delete pizza_list; //we don't have to delete pizza_copy_ptr and if there exist drink because they will be deleted in pizza_list and drink_list
                return;
            }
            if (!customer_name_check)
            { //if customer name miss written it prints an error message and gives instructions
                cout << endl
                     << "If you want to return main menu press 0" << endl;
                cout << "There is another customer named " << customer_name << " please try another name: " << endl;
            }
        }
    }
    else
    {
        cin >> customer_name; //if there is not any other just get customer name
    }

    cout << endl;
    if (drink_list->getDHead() != NULL)
    {                                                                   //if there is a drinklist
        order_ptr = new Order(customer_name, *pizza_list, *drink_list); //we create an order that is holding a customer name, ordered pizzas and ordered drinks
        order_num++;                                                    // we increase number of the orders
        this->addOrder(*order_ptr);                                     //we add our order to orderlist
        order_ptr->printOrder();                                        //and we print our orders in the console
        cout << endl;
    }
    else
    {                                                      // if we don't have any drinklist
        order_ptr = new Order(customer_name, *pizza_list); // we create a new order without drink
        order_num++;                                       // we increase the order num
        this->addOrder(*order_ptr);                        //we add our order to order list
        order_ptr->printOrder();                           //and we print our orders in the console
        cout << endl;
        delete drink_list; //and because we didn't use our drinklist we have to delete it to prevent memory leak
    }
    cout << "Your order is saved, it will be delivered when its ready" << endl
         << endl;
}

void OrderList::addOrder(Order &neworder)
{ //in this function we add orders to orderlist
    ONode *traverse;
    ONode *newnode;
    newnode = new ONode(neworder); //we create a new ONode(Order Node) with in order
    traverse = this->OHead;        //assign the head of the list to traverse
    if (this->OHead == NULL)
    {                          //if head of the orderlist is empty
        this->OHead = newnode; //we assign our ordernode to our head
        return;
    }
    while (traverse->getNext())
    { //we take our pointer until the last order node
        traverse = traverse->getNext();
    }
    traverse->setNext(*newnode); //and add our new ordernode to next of the last node
}

void OrderList::listOrders()
{ //in this function we print our all orders datas
    if (this->OHead != NULL)
    {
        ONode *traverse;
        traverse = this->OHead; // we assign our orderlist head to traverse
        int i = 1;
        while (traverse)
        {
            cout << endl;
            cout << i << endl;                  //we print order num of the each order
            traverse->getOrder()->printOrder(); //we print each of the orders one by one
            traverse = traverse->getNext();
            i++;
        }
        cout << endl;
    }
    else
    {
        cout << endl
             << "Order List is empty" << endl
             << endl;
    }
}

void OrderList::deliverOrders() // in this function we deliver our orders and remove from the orderlist
{
    ONode *traverse;        //for tracking our orders
    PNode *traversePizza;   //for tracking our pizzas in the each one of the orders
    DNode *traverseDrink;   //for tracking our drinks in the each one of the orders
    traverse = this->OHead; //assign order head to traverse
    string customer_name;
    this->listOrders();       // print all orders
    double total_price = 0.0; //total price
    string check_promotion;   //if our customer gives us a promotion code for discount
    string promotion_code;    //promotion code
    cout << "Please write the customer name in order to deliver his/her order: ";
    bool customer_name_check = false; //if there is a customer named given name
    while (!customer_name_check)
    {                         //while customer name is not found
        cin >> customer_name; //take customer name
        while (traverse && customer_name != "0")
        { //while order is exist and customer name is not 0
            if (customer_name == traverse->getOrder()->getCustomerName())
            {                               //if customer name is equal one of the orders
                customer_name_check = true; //customer check is true
            }
            traverse = traverse->getNext();
        }

        traverse = this->OHead;
        if (customer_name == "0")
        { //if customer wants to return to main menu press 0 and return
            return;
        }
        if (!customer_name_check)
        { //if customer name miss written it prints an error message and gives instructions
            cout << endl
                 << "If you want to return main menu press 0" << endl;
            cout << "There is no customer named " << customer_name << " please try another name: " << endl;
        }
    }
    cout << endl
         << "Following order is delivering" << endl;
    while (traverse)
    {

        if (customer_name == traverse->getOrder()->getCustomerName())
        { //print choosen order that will be delivered
            cout << "------------" << endl;
            cout << "Name: " << traverse->getOrder()->getCustomerName() << endl
                 << endl;                                                  //print customer name
            traversePizza = traverse->getOrder()->getPizzas()->getPHead(); //assign pizzas head to traversepizza
            while (traversePizza)
            { //print each of the pizzas that ordered
                cout << traversePizza->getAmount() << "x " << traversePizza->getPizza()->getName() << "(" << traversePizza->getPizza()->getIngredients()->getdata() << ")" << endl;
                cout << "size: " << traversePizza->getPizza()->getSize() << ", "
                     << "crust : " << traversePizza->getPizza()->getCrustType() << endl
                     << endl;
                traversePizza = traversePizza->getNext();
            }
            if (traverse->getOrder()->getDrinks() != NULL)
            {                                                                  //if order has any drinks
                traverseDrink = traverse->getOrder()->getDrinks()->getDHead(); //assign drinks head to traversedrink
                if (traverseDrink != NULL)
                { //if drinklist is not empty
                    while (traverseDrink)
                    { //print each one of the drinks
                        cout << traverseDrink->getAmount() << "x " << traverseDrink->getDrink()->getName() << ", ";
                        traverseDrink = traverseDrink->getNext();
                    }
                    cout << endl;
                }
            }
            cout << "------------" << endl;
            total_price = traverse->getOrder()->getPrice(); //get order price from the order's getPrice function
            break;                                          //beacuse we find the correct order we have to break our loop
        }
        traverse = traverse->getNext();
    }
    cout << "Total price: " << total_price << " TL" << endl; // print total price
    cout << "Do you have a promotion code? (y/n)" << endl;
    cin >> check_promotion; //if we have any promotion code
    if (check_promotion == "y")
    { //we have a promotion code
        cout << "If you don't want to use promotion code press 0." << endl;
        while (true)
        {
            getline(cin >> ws, promotion_code); //we get our promotion code (cin>>ws get our input with whitespaces)
            if (promotion_code == "I am a student")
            {                                                 //if promotion code is correct
                total_price = total_price - total_price / 10; //we discount our order 10%
                cout << endl;
                cout << "Dicounted price: " << total_price << " TL" << endl
                     << endl; //print discounted price
                break;        //because we discounted our price we have to break our loop
            }
            else if (promotion_code == "0")
            { //if we miss write to promotion check we write 0 and we get our final pricewithout discount
                cout << endl;
                cout << "Total price: " << total_price << " TL" << endl
                     << endl;
                break;
            }
            else
            { //if we write an incorrect code its ask us again
                cout << endl;
                cout << "Incorrect promotion code please try again!!" << endl;
            }
        }
    }
    else
    {
        cout << "Total price: " << total_price << " TL" << endl; // print total price
    }
    this->removeOrder(customer_name); //and we remove the delivered order from our ordelist
    cout << "The order is delivered succesfully!" << endl
         << endl;
}

void OrderList::removeOrder(string customer_name)
{ //in this function we remove our order from order list
    ONode *traverse;
    ONode *temp;
    if (this->OHead->getOrder()->getCustomerName() == customer_name)
    {
        temp = this->OHead->getNext(); //if our order is the first node we had to keep second node
        this->order_num--;             //we decrease order num
        delete this->OHead;            //we delete first node
        this->OHead = temp;            //and we assign our second node to orderlist's head node
        return;
    }
    temp = this->OHead;                //we assign our head to temp
    traverse = this->OHead->getNext(); //we assign our order's next node to traverse
    while (traverse)
    { //if our orderlist has next ordernode
        if (traverse->getOrder()->getCustomerName() == customer_name)
        {
            //if traverse customer name equals to choosen customer
            temp->setNext(*traverse->getNext()); //we assign our temp's next to the node we will delete
            this->order_num--;                   //we decrease order number
            delete traverse;                     //delete our order
            return;
        }
        temp = traverse;
        traverse = traverse->getNext();
    }
}

void OrderList::removeAllOrder(ONode &temp)
{ //in this function we remove all of the orders with recursive aproach
    if (temp.getNext() != NULL)
    {                                    //if our node has a next node
        removeAllOrder(*temp.getNext()); // we call this function with next node
    }

    //if there is not any next node its broke the recursive loop

    //after we can't find any next node and if our node is exist
    delete &temp; //we delete the node (it is always the last node of the list)
}

OrderList::~OrderList()
{ //destructor of the orderlist when we delete orderlist we have to delete other objects in the orderlist as well
    if (this->OHead != NULL)
    {                                 //if our list is not empty
        removeAllOrder(*this->OHead); //we call removeallorder function and remove all of the orders
    }
}

bool isNumber(string data) //this function controls if given amount is a valid integer
{
    for (int i = 0; i < int(data.length()); i++)
    {
        if (isdigit(data[i]) == false)
        {
            return false;
        }
    }
    return true;
}

#endif
