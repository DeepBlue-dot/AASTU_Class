#include <iostream>

using namespace std;

int main()
{
    int row;
    cout << "Enetr row:\t";
    cin >> row;
    for(int i=1; i<=row; i++)
    {
        for(int j = row; j>0; j--)
        {
            if(i >=j)
                cout <<i;
            else
                cout <<" ";
        }
        cout << endl;
    }
}