#include <iostream>

using namespace std;

int main()
{
    int num;
    cout << "Enter number: \t";
    cin >> num;
    for(int i = num; i > 0; i--)
    {
        cout << i << "\t";
    }
}