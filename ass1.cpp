#include <iostream>

using namespace std;

int main()
{
    int num;
    cout << "Enter number:\t";
    cin >> num;
  
    for(int i = num; i>=0; i--)
    {
        for(int j=0; j <= i; j++)
        {
            cout << j;
        }
        for(int k=0; k<2*(num-i); k++)
        {
            cout << " ";
        }
        for(int j=i; j>=0; j--)
        {
            cout << j;
        }
        cout << endl;
    }
    for(int i = 1; i<=num; i++)
    {
        for(int j=0; j <= i; j++)
        {
            cout << j;
        }
        for(int k=0; k<2*(num-i); k++)
        {
            cout << " ";
        }
        for(int j=i; j>=0; j--)
        {
            cout << j;
        }
        cout << endl;
    }
}