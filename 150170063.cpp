/*
    Name    : Burak
    Surname : Şen
    ID      : 150170063
    Date    : 26.03.2020
*/
#include <iostream>
#include "OrderList.h"

using namespace std;

int main() {
    string option = "1";//for chooseing functions of the orderlist

    OrderList* orderList;//orderlist pointer
    orderList = new OrderList();// new orderlist created

    while (option != "0")
    {
        cout << "Welcome to Unicore Pizza!" << endl
            << "1. Add an order" << endl
            << "2. List orders" << endl
            << "3. Deliver order" << endl
            << "0. Exit" << endl
            << "Choose what to do: ";

        cin >> option;

        if(option == "0"){//if option is 0 break the loop and than terminate
            break;
        }
        else if(option == "1"){//if option is 1 call takeOrder function from orderlist
            orderList->takeOrder();
        }
        else if(option == "2"){//if option is 2 call listOrders function from orderlist
            orderList->listOrders();
        }
        else if(option == "3"){//if option is 3 call deliverOrders function from orderlist
            orderList->deliverOrders();
        }
        else{
            cout << endl;
            cout << "Please enter a valid input" << endl;
            cout << endl;
        }
    }
    cout<<endl<<"Goodbye..."<<endl;
    delete orderList;
    return 0;
}