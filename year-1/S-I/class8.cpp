#include <iostream>

using namespace std;

int main()
{
    int num, total = 1, po;
    cout << "Enter number:\n";
    cin >> num;
    for(int i =num; i > 1; i--)
    {
        total*=i;
    }
    cout << total;
    
}