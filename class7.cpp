#include <iostream>

using namespace std;

int main()
{
    int num, total = 0;
    bool run = true;
    cout << "Enter number:\n";
    cin >> num;
    while (num != 0)
        cout << num%10;
    num = num/10;
    
    return 0;
    
}