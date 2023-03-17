#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int num, dighit,sum = 0, p = 0;
    cout << "Enet naum \t";
    cin >> num;

    for(int i = num; i != 0; )
    {
        dighit = i % 10;
        i = i/10;
        int mult = 1;
        for(int j = dighit; j > 0; j--)
        {
            mult *= j;
        }
        sum += mult;
    }
    if(num == sum)
    {
        cout << "Is sTRONG" << endl;
    }
    else
    {
        cout << "Is not sTRONG" << endl;
    }

        
}