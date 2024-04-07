 #include <iostream>
 #include <string>
 #include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include<limits>
 using namespace std;

 int main() {

string word, line;

cout << "enter a word" << endl;
cin >> word;

cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

cout << "enter a line" << endl;
getline(cin, line);

cout << "your word is " << word << endl;
cout << "your line is " << line << endl;

return 0;
}