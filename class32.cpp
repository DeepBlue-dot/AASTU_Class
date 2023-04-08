#include <iostream>

using namespace std;

int main()
{
    int row, colu;
    cout << "Enetr row:\t";
    cin >> row;
    cout << "Enetr column:\t";
    cin >> colu;
    for(int i=0; i<colu; i++)
    {
        for(int j=0; j<row; j++)
        {
            cout <<"*";
        }
        cout << endl;
    }
}