#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int num, dighit, p = 0;
    cout << "Enet naum \t";
    cin >> num;
    for (int q = num; q > 0; q--)
    {
        int sum = 0;
        for(int i = q; i != 0; )
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
        if(q == sum)
        {
            cout << sum << " ";
        }

    }
    

        
}