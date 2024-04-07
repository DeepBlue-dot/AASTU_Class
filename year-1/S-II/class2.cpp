#include <iostream>

using namespace std;

void input(int no, int marks[][2])
{
    char m;
    for(int i = 0; i < no; i++)
    {
        cout << "enter course " << i+1 << " mark:"<< endl;
        cin >> m;
        cout << "enter course " << i+1 << " credit hour:"<< endl;
        cin >> marks[i][1];
        if (m=='A')
        {
            marks[i][0]=4;
        }
        else if (m=='B')
        {
            marks[i][0]=3;
        }
        else if (m=='C')
        {
            marks[i][0]=2;
        }
        else if (m=='D')
        {
            marks[i][0]=1;
        }
        else if (m=='F')
        {
            marks[i][0]=0;
        }
    }
}

int calculat(int no, int marks[][2], int grade[])
{
    int total=0;
    int sum=0;
    for(int i =0; i < no;i++)
    {
        grade[i]=marks[i][0]*marks[i][1];
        sum+=grade[i];
        total+=marks[i][1];
    }
    return sum/total;
}

void display(float gpa,int no, int marks[][2], int grade[])
{
    cout << "marks\t cr_hr\tgrade:\n";
    for(int i=0; i<no;i++)
    {
        cout <<marks[i][0] << "\t"<< marks[i][1] <<"\t" <<grade[i]<< endl;
    }
    cout<< "gpa = " <<gpa<< endl;
}

int main(void)
{
    int num;
    float gpa;
    cout << "enter number of courses:\t";
    cin >> num;
    int mark[num][2];
    int grade[num];



    input(num,mark);
    gpa=calculat(num,mark,grade);
    display(gpa,num,mark,grade);
    
}