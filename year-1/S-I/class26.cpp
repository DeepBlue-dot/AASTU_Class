#include <iostream>

using namespace std;

int main()
{
    int num;
    cout << "Enter number:\t";
    cin >> num;
    for (int i = num; i > 0; i--)
    {
        int sum = 0;
        for (int j = 1; j < i; j++)
        {
            if(i%j == 0)
            {
                sum += j;
            }
        }
        if(i == sum)
            cout <<i << "\t";
    }

}