#include <iostream>

using namespace std;

int main()
{
    int num, dighit;
    cout << "Enter number:\t";
    cin >> num;
    for (int q = num; q > 0; q--)
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
            if(num == sum)
                cout << num <<" is armstrong.\n";
            else
                cout << sum <<" "; 
           
        }
    }
        
}