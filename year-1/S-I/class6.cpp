#include <iostream>

using namespace std;

int main()
{
    int num, total = 0;
    cout << "Enter number:\n";
    cin >> num;
    for(int i =10; i <= 10000; i*=10 )
    {
        cout << num%10;
        num = num/i;
    }
    
}