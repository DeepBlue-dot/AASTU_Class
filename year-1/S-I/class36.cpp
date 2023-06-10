#include <iostream>

using namespace std;

int main()
{
    int row;
    cout << "Enetr row:\t";
    cin >> row;
    for(int i=0; i<row; i++)
    {
        for(int j = 0; j<row-i; j++)
        {
            cout <<" ";
        }

        for(int j = -1; j<=(i+(i-1)); j++)
        {
            cout <<j;
        }
        cout << endl;
    }
}