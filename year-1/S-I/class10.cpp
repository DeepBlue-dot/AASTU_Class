#include <iostream>

using namespace std;

int main()
{
    int num, total = 1, po;
    cout << "Enter number:\n";
    cin >> num >> po;
    for(int i =1; i <= po; i++ )
    {
        total*=num;
    }
    cout << total;
    
}