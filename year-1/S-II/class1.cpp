#include <iostream>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include<limits>


using namespace std;

struct  Student
{
    
    float gpa=0;
    int no_courses=0;
    int mark[50][2]{};
    int grade[50]{};
};


void input(Student &stu)
{
    char m;
    cout << "enter number of courses:\t";
    cin >> stu.no_courses;
    for(int i = 0; i < stu.no_courses; i++)
    {
        cout << "enter course " << i+1 << " mark:"<< endl;
        cin >> m;
        cout << "enter course " << i+1 << " credit hour:"<< endl;
        cin >> stu.mark[i][1];
        if (m=='A')
        {
            stu.mark[i][0]=4;
        }
        else if (m=='B')
        {
            stu.mark[i][0]=3;
        }
        else if (m=='C')
        {
            stu.mark[i][0]=2;
        }
        else if (m=='D')
        {
            stu.mark[i][0]=1;
        }
        else if (m=='F')
        {
            stu.mark[i][0]=0;
        }
    }
}

void calculat(Student &stu)
{
    int total=0;
    int sum=0;
    for(int i =0; i < stu.no_courses;i++)
    {
        stu.grade[i]=stu.mark[i][0]*stu.mark[i][1];
        sum+=stu.grade[i];
        total+=stu.mark[i][1];
    }
    stu.gpa=sum/total;
 }

void display(Student &stu)
{
    cout << "marks\t cr_hr\tgrade:\n";
    for(int i=0; i<stu.no_courses;i++)
    {
        cout <<stu.mark[i][0] << "\t"<< stu.mark[i][1] <<"\t" << stu.grade[i]<< endl;
    }
    cout<< "gpa = " << stu.gpa<< endl;
}

int search(int& num, Student books[])
{
    int c=0,n;
    string search_isbn;
    cout <<"Search by\n" << "\t1.Book number\n" << "\t2.ISBN" << endl;
    cin >> c;
    switch (c)
    {
        case 1:
            cout << "Enter Book number: ";
            cin >> n;
            if(n>0 && n <= num)
            {
                cout << "Book " << n << endl; 
                display(books[n-1]);
                return n-1;
            }
            else
            {
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            break;
        case 2:
            cout << "Eneter Book ISBN: ";
            cin >> search_isbn;
            if(search_isbn.length() == 13)
            {
                for (int i = 0; i < num; i++)
                {
                    if(search_isbn==books[i].ISBN)
                    {
                        cout << "Book " << i+1 << endl; 
                        display(books[i]);
                        return i;
                    }
                    else if (i == num-1)
                    {
                        cout << "Book not found" << endl;
                    }
                    
                }    
            }
            else
            {
                cout << "Invalid Input" << endl;
            }
            break;
        
        default:
            cout << "Invalid Input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
    }
    return -1;
}

int main(void)
{
    Student student;
    input(student);
    calculat(student);
    display(student);
}