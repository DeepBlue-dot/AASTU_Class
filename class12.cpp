#include <iostream>

using namespace std;

int main()
{
    int num, dighit,sum = 0;
    cout << "Enet naum \t";
    cin >> num;
    for(int i = num; i != 0; )
    {
        dighit = i % 10;
        int mult =1;
        for(int j = num; j != 0; )
        {
            j = j/10;
            mult*=dighit;
        }
        i = i/10;
        sum += mult;
    }
    if(num == sum)
    {
        cout << "Is ARMSTRONG" << endl;
    }

        
}