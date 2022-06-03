#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;


class Flight
{
private:
    int fightNo;
    string destinaton;
    float distance, fuel;

private:
    void calFuel()
    {
        if(distance <= 1000)
            fuel = 500;
        else if(distance <= 2000)
            fuel = 1100;
        else
            fuel = 2200;
    }

public:
    void feedInfo()
    {
        cout << "Flight number: ";
        cin >> fightNo;
        cout << "Destinaton: ";
        cin >> destinaton;
        cout << "Distance: ";
        cin >> distance;

        calFuel();
    }

    void showInfo()
    {
        cout << "Flight number: " << fightNo << endl;
        cout << "Destinaton: " << destinaton << endl;
        cout << "Distance: " << distance << endl;
        cout << "Fuel:" << fuel << endl;
    }
};


class Book
{
private:
    int bookNo;
    string bookName;
    float price;
    int N;

private:
    float totalCost(int n)
    {
        return n*price;
    }

public:
    void Input()
    {
        cout << "Book number: " << bookNo << endl;
        cout << "Book Name: " << bookName << endl;
        cout << "Price: " << price << endl;
    }

    void Purchase()
    {
        cout << "Number of copies: ";
        cin >> N;
        printf("Total: %d\n", totalCost(N));
    }
};


class Report
{
private:
    int adno;
    string name;
    float marks[5];
    float avg;

private:
    float getAvg()
    {
        float sum = 0
        for(int i=0; i<5 i++)
        {
            sum = sum + marks[i];
        }

        return sum/5;
    }

public:
    void redInfo()
    {
        cout << "adNo: ";
        cin >> adno;
        cout << "Name: ";
        cin >> name;
        cout << "Marks: ";
        for(int i=0; i<5; i++)
            cin >> marks[i];

        avg = getAvg();
    }

    void displayInfo()
    {
        cout << "adNo: " << adno << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: ";
        for(int i=0; i<5; i++)
            cout << marks[i] << ",";
        cout << endl << "Avg: " << avg < endl;
    }
}

int main()
{
    
}