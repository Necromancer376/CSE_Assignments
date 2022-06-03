#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;


class Tollbooth
{
private:
    unsigned int cars;
    double money;

public:
    Tollbooth()
    {
        cars = 0;
        money = 0;
    }

    void payingcars()
    {
        cars++;
        money += 0.5;
    }

    void nopaycars()
    {
        cars++;
    }

    void display()
    {
        system("clear");
        cout << endl << "------- Tollbooth -------" << endl;
        cout << "Number of Cars passed: " << cars << endl;
        cout << "Total money: " << money << endl;
        cout << "-------------------------" << endl << endl;
    }
};


int main(void)
{
    Tollbooth toll;
    int input;
    
    cout << "1. Paying Cars\n2. Non-paying Cars\n3. Display\n0. Exit\nInput: ";
    cin >> input;

    while(input != 0)
    {
        switch(input)
        {
            case 1:
                toll.payingcars();
                toll.display();
                break;
            case 2:
                toll.nopaycars();
                toll.display();
                break;
            case 3:
                toll.display();
                break;
            case 0:
                input = 0;
                break;
            default:
                cout << "Invalid Input" << endl;
                break;
        }

        cout << endl << "1. Paying Cars\n2. Non-paying Cars\n3. Display\n0. Exit\nInput: ";
        cin >> input;
    }
}