#include <iostream>

using namespace std;

class student
{
private:
    int rollNo;

public:
    void get_number(){ cin >> rollNo; }
    void put_number() { cout << rollNo << endl; }
};

class test : public student
{
protected:
    int sub1, sub2;

public:
    void get_marks() { cin >> sub1 >> sub2; }
    void put_marks() { cout << sub1 << endl << sub2 << endl; }
};

class sports
{
protected:
    int sp_marks;

public:
    void get_sp() { cin >> sp_marks; }
    void put_sp() { cout << sp_marks << endl; }
};

class result : public test, public sports
{
private:
    int total;

public:
    void display()
    {
        cout << sub1 + sub2 + sp_marks << endl;
    }
};


int main(void)
{
    result obj;

    obj.get_number();
    obj.get_marks();
    obj.get_sp();

    obj.display();

    return 0;
}