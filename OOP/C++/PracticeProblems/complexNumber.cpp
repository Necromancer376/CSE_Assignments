#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    Complex()
    {

    }
    Complex(double a, double b)
    {
        real = a;
        imag = b;
    }

    Complex operator*(Complex a2)
    {
        Complex a;  
        a.real = (real * a2.real) - (imag * a2.imag);
        a.imag = (real * a2.imag) + (imag * a2.real);
        return a;
    }

    Complex operator/(Complex a2)
    {
        Complex a;
        a.real = ((real * a2.real) + (imag * a2.imag)) / ((a2.real * a2.real) + (a2.imag * a2.imag));
        a.imag = ((imag * a2.real) - (real * a2.imag)) / ((a2.real * a2.real) + (a2.imag * a2.imag));
        return a;
    }

    void Print()
    {
        cout << real << " + " << imag << "i" << endl;
    }

};


int main()
{
    double a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    Complex a(a1, b1);
    Complex b(a2, b2);
    Complex c;

    c = a * b;
    c.Print();

    c = a / b;
    c.Print();

    if(a1 == a2 && b1 == b2)
    {
        cout << "Sure they are equal" << endl;
    }
    else
        cout <<  "Sure they are not equal" << endl;
}