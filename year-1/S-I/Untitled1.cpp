#include <iostream>
using namespace std;

int main()
{
    int num[3][2]={1,2,3,4,5};
    for(int i=1; i<=2; i++)
    {
        for(int j = 0; j<=1; j++)
        {
            cout << num[i][j] << "\t";
        }

    }
}
