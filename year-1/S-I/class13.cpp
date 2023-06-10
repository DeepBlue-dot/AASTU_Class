#include <iostream>

using namespace std;

int main()
{
    int num, dighit;
    cout << "Enter number:\t";
    cin >> num;
    int q = num;
    do 
    {
        int sum = 0;
        int i = q; 
        do
        {
            dighit = i % 10;
            int mult =1;
            int j = q;
            do
            {
                j = j/10;
                mult*=dighit;
            }while( j != 0);
            i = i/10;
            sum += mult;
        }while(i != 0);
        if(q == sum)
        {
            if(num == sum)
                cout << num <<" is armstrong.\n";
            else
                cout << sum <<" "; 
           
        }
        q--;
    }while (q > 0);
       
        
}