#include<iostream>
#include<string.h>

using namespace std;


class string
{
    char *p;
    int len;

public:
    string() {len = 0; p = 0}
    string(const char *s);
    string(const string &s);
    ~string() { delete p};
    friend string operator+(const string &s, const string &t);
    friend int operator<=(const string &s, const string &t);
    friend void show(const string s);
};

string::string(const char *s)
{

}

string::string(const string &s)
{
    
}

operator+()
{
    
}
operator-()
{
    int m = strlen(s.p);
    int n = strlen(t.p);

    if (m <=n )
        return 1;
    else
        return 0;
}

void show(const string s)
{
    cout << s.p << endl;;
}

int main(void)
{

}