#include<iostream>
#include<string.h>

using namespace std;

class MathSymbol
{
public:
    virtual int doOperation(int x, int y) = 0;
};

class Plus : public MathSymbol
{
public:
    int doOperation(int x, int y)
    {
        return x + y;
    }
};

class Minus : public MathSymbol
{
public:
    int doOperation(int x, int y)
    {
        return x - y;
    }
};


int main(void)
{
    Plus obj1;
    Minus obj2;

    cout << obj1.doOperation(5, 8) << endl;
    cout << obj2.doOperation(11, 4) << endl;
}