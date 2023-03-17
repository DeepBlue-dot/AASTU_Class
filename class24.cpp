#include <iostream>

using namespace std;

int main ()
{
    int num;
   do
   {
        cout << "Enter any number other than 5:\t";
        cin >> num;
   } while (num != 5);
   cout << "Hey! You weren’t supposed to enter 5!" << endl;
   
}