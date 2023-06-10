#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num, sub, total =0;

    cout << "Enter number of student:\t";
    cin >> num;
    cout << "Enter number of subject:\t";
    cin >> sub;

    int mark [num][sub];
    string name [num];

    for(int i =0; i < num; i++)
    {
        cout << "Enter student-" << i+1 << "\'s name:\t";
        cin >> name[i];
        for(int j=0; j<sub; j++)
        {
            cout <<" Enter C-" << j+1 << " mark:\t";
            cin >> mark[i][j];
        }
    }

    cout << "Name\t";
    for(int i = 0; i < sub; i++)cout << "C" << i+1 << "\t";
    cout << "Total\n";

    for(int i =0; i < num; i++)
    {
        cout << name[i] << "\t";
        for(int j=0; j<sub; j++)
        {
            cout << mark[i][j] << "\t";
            total += mark[i][j];
        }
        cout << total << endl;
        total = 0;
    }
}