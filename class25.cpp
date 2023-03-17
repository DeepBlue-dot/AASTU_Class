#include <iostream>

using namespace std;

int main()
{
    int num, sum = 0;
    cout << "Enter number:\t";
    cin >> num;
    for (int i = 1; i < num; i++)
    {
        if(num%i == 0)
        {
            sum += i;
        }
    }
    if(num == sum)
        cout <<"Is perfect.\n";
    else
        cout <<"Is not perfect.\n";
}