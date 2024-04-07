#include <iostream>

using namespace std;

inline void swap(int a , int b)
{
    int temp = a;
    a=b;
    b=temp;
}

int &add(int a, int b)
{
    int c = a+b;
    return c;
}

void rswap(int &a, int &b)
{
    int temp = a;
    a=b;
    b=temp;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}



int main()
{
    int a=10,b=5;
    cout << "value\nbefore " << a << " " << b<<endl;
    swap(a,b);
    cout << "after " << a << " " <<b<<endl;
    cout << "reference \nbefore " << a << " " <<b<<endl;
    int test[2]={1,2};
    rswap(test[0],b);
    cout << "after " << a << " " <<b << endl;
    cout << "pointer\nbefore " << a << " " <<b<<endl;
    swap(&a,&b);
    cout << "after " << a << " " <<b << endl;
    int &d=add(4,5);
    cout << add(4,5);
}