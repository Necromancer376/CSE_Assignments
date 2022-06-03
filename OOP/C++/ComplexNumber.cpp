#include<iostream>
#include<string.h>

using namespace std;


class Complex
{
private:
    float x, y;

public:
    Complex(){};
    Complex(float a, float b)
    {
        x = a;
        y = b;
    }

    Complex operator+(Complex);
    Complex operator-(Complex);

    void Display()
    {
        cout << x << " + " << y << "i" <<  endl;
    }
};

Complex Complex::operator + (Complex c)
{
    Complex  temp;
    temp.x = x + c.x;
    temp.y = y + c.y;

    return temp;
}

Complex Complex::operator - (Complex c)
{
    Complex  temp;
    temp.x = x - c.x;
    temp.y = y - c.y;

    return temp;
}


int main(void)
{
    Complex c1, c2, c3;

    c1 = Complex(5.2, 2.1);
    c2 = Complex(3.7, 4.4);

    cout << "c1: ";
    c1.Display();
    cout << "c2: ";
    c2.Display();
    cout << endl;

    cout << "operator+" << endl;
    c3 = c1 + c2;
    c3.Display();
    cout << endl;

    cout << "operator-" << endl;
    c3 = c1 - c2;
    c3.Display();
    cout << endl;

    return 0;
}