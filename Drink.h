/*  Name    : Burak
    Surname : Şen
    ID      : 150170063
    Date    : 26.03.2020
*/

#ifndef _DRINK
#define _DRINK
#include <string>
using namespace std;

class Drink
{
private:
    string name; //define drink name

public:
    Drink(string); //drink constructor
    ~Drink();      //drink destructor
    string getName();
};

Drink::Drink(string data)
{
    this->name = data; //we assign data to drink name
}

string Drink::getName()
{
    return this->name;
}

Drink::~Drink() {} //empty constructor we don't have any variable with allocated memory in the drink class

#endif