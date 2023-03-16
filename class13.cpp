#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int num, dighit;
    cout << "Enet naum \t";
    cin >> num;
    for (int q = 1; q < num; q++)
    {
        int sum = 0;
        for(int i = q; i != 0; )
        {
            dighit = i % 10;
            int mult =1;
            for(int j = q; j != 0; )
            {
                j = j/10;
                mult*=dighit;
            }
            i = i/10;
            sum += mult;
        }
        if(q == sum)
        {
            cout << sum <<" ";
        }
    }
        
}