#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    cout << "Enter number:\n";
    getline(cin, name);

    for (int i = name.length() ; i >= 0; i--)
    {
        cout << name[i];
    }
    return 0;
    
}