#include <iostream>

using namespace std;

struct student
{
    string name;
    int age;
    char sex;
    int id;
    float mark[3];
};

struct list
{
    student *arr[100];
    int size[100]{0};
    int no=0;
};


student * add(int& size)
{
    cout << "Enter naumber of student." << endl;
    cin >> size;
    student *arr = new student[size];
    for (size_t i = 0; i < size; i++)
    {
        cout << "Enter student "<< i+1 << endl;
        cout << "\tName: ";
        cin >> arr[i].name;
        cout << "\tAge: ";
        cin >> arr[i].age;
        cout << "\tSex: ";
        cin >> arr[i].sex;
        cout << "\tID: ";
        cin >> arr[i].id;
        for (size_t j = 0; j < 3; j++)
        {
            cout << "\tGrade " << j+1 <<": ";
            cin >> arr[i].mark[j];
        }
    }
    return arr;
}

void display(list ls)
{
    cout << "ID\t" << "Age\t" << "sex\t" << "Grade 1\t" << "Grade 2\t" << "Grade 3\n";
    for (size_t j = 0; j < ls.no; j++)
    {
        for (size_t i = 0; i < ls.size[j]; i++)
        {
            cout << ls.arr[j][i].id << "\t";
            cout << ls.arr[j][i].age << "\t";
            cout << ls.arr[j][i].sex << "\t";
            for (size_t k = 0; k < 3; k++)
            {
                cout << ls.arr[j][i].mark[k] << "\t";
            }
            cout << endl;
        }
    }    
}

int main(void)
{
    int size=0, choice;
    student* students;
    list ls;
    while (true)
    {
        cout << "1.Add" << endl << "2.Display" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
                system("clear");
                ls.arr[ls.no] = add(size);
                ls.size[ls.no]=size;
                ls.no+=1;
                break;
            case 2:
                system("clear");
                display(ls);
                break;
            
            default:
                break;
        }
    }
}