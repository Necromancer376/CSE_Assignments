#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;


class cashReg
{
private:
    int cashOnHand;

public:
    cashReg()
    {
        cashOnHand = 500;
    }
    cashReg(int ammount)
    {
        cashOnHand = ammount;
    }

    int  getBal()
    {
        return cashOnHand;
    }

    void acceptAmmount(int ammount)
    {
        cashOnHand += ammount;
    }
};


class DispencerType
{
private:
    int numItems;
    int costItem;

public:
    DispencerType()
    {
        numItems = 50;
        costItem = 50;
    }

    DispencerType(int num, int cost)
    {
        numItems = num;
        costItem = cost;
    }

    int getNumItems()
    {
        return numItems;
    }

    int getCost()
    {
        return costItem;
    }

    void makeSale()
    {
        numItems--;
    }

    void Print()
    {
        cout << costItem << "\t" << numItems << endl;;
    }
};


int main(void)
{
    cashReg cash;
    DispencerType items[4];
    string list[4] = {"candy", "chips", "gum", "cookie"};
    int choice;

    cout << "Item\tPrice\tStock" << endl;
    for(int i = 0; i<4; i++)
    {
        cout << list[i] << "\t";
        items[i].Print();
    }

    cout << "1.candy\n2.chips\n3.gum\n4.cookie\n5.CashReg\n0.exit\nChoice: ";
    cin >> choice;

    while(choice != 0)
    {
        if(choice == 5)
        {
            printf("Bal: %d\n",cash.getBal());
        }

        else     
        {
            items[choice - 1].makeSale();
            cash.acceptAmmount(items[choice - 1].getCost());
        }

        cout << "Item\tPrice\tStock" << endl;
        for(int i = 0; i<4; i++)
        {
            cout << list[i] << "\t";
            items[i].Print();
        }
        cout << "1.candy\n2.chips\n3.gum\n4.cookie\n0.exit\nChoice: ";
        cin >> choice;
    }

    return 0;
}