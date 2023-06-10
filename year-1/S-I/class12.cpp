#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int num, dighit,sum = 0, p = 0;
    cout << "Enet naum \t";
    cin >> num;
    for(int j = num; j != 0; )
    {
        j = j/10;
        p ++;
    }
    for(int i = num; i != 0; )
    {
        dighit = i % 10;
        i = i/10;
        int mult = pow(dighit, p);
        sum += mult;
    }
    if(num == sum)
    {
        cout << "Is ARMSTRONG" << endl;
    }

        
}