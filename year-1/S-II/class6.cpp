#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits>


using namespace std;

struct student
{
    int id,age;
    string name;
    string sex;
    double grade[3]{-1};
    void get_sex()
    {
        cout << "Enter sex:" << endl;
        cin.ignore();
        while (true)
        {
            getline(cin, sex);
            if(sex=="f" ||sex=="F" ||sex=="M" ||sex=="m")
            {
                break;
            }
            else
            {
                cout << "there are only 2 genders" << endl;
            }
        }
        
    }
    void get_age()
    {
        cout << "Enter age:" << endl;
        while (true)
        {
            if (cin >> age)
            {
                if(age >4 && age < 30)
                {
                    break;
                }
                else
                {
                    cout << "ur too old" << endl;
                }
            }
            else
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        
    }
     void get_name()
    {
        cin.ignore();
        cout << "Enter name:" << endl;
        do
        {
            getline(cin, name);
        } while (name.length() < 4);
    }
    void get_grade()
    {
        for (size_t j = 0; j < 3; j++)
        {
            cout << "enter course " << j+1 << " grade:"<< endl;
            while (true)
            {
                if (cin >> grade[j])
                {
                    if (grade[j] >= 0 && grade[j] <=100)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Invalid Grade" << endl;
                    }
                    
                }
                else
                {
                    cout << "Invalid inuput!!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            
        }        
    }
    void output()
    {
        cout <<"student id: " << id << endl;
        cout <<"student name: " << name << endl;
        cout <<"student sex: " << sex << endl;
        cout <<"student age: " << age << endl;
        for (size_t j = 0; j < 3; j++)
        {
            cout << "student course " << j+1 << " grade: "<< grade[j] << endl;
        }
    }

};

int c_id;

void input (vector<student> &arr);
void save_books(vector<student> &arr);
void load_book(vector <student> &the);
void sreacrh(vector <student> the);
void edit(vector<student> &the);


void input (vector<student> &arr)
{
    student the;
    int num;
    cout << "Enter number of student:\t";
    if(cin >>num)
    {
        for (size_t i = 0; i < num; i++)
        {
            the.id=c_id++;        
            the.get_name();
            the.get_age();
            the.get_sex();
            the.get_grade();
            arr.push_back(the);
        }
        save_books(arr);
    }
    else
    {
        cout << "Invalid Input." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void save_books(vector<student> &arr)
{
    ofstream fout ("students.txt");
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size()-1)
        {
            fout << arr[i].id << endl;
            fout << arr[i].name << endl; 
            fout << arr[i].age << endl; 
            fout << arr[i].sex << endl; 
            fout << arr[i].grade[0] << endl; 
            fout << arr[i].grade[1] << endl; 
            fout << arr[i].grade[2]; 
        }
        else
        {
            fout << arr[i].id << endl;
            fout << arr[i].name << endl; 
            fout << arr[i].age << endl; 
            fout << arr[i].sex << endl; 
            fout << arr[i].grade[0] << endl; 
            fout << arr[i].grade[1] << endl; 
            fout << arr[i].grade[2] << endl; 
        }
        
    }
    fout.close();  
}

void load_book(vector <student> &the)
{
    ifstream fin ("students.txt");
    if(fin.is_open())
    {
        while (!fin.eof())
        {
            student temp;
            fin>>temp.id;
            fin.ignore();
            getline(fin, temp.name);
            fin>>temp.age;
            fin>>temp.sex;
            fin>>temp.grade[0];
            fin>>temp.grade[1];
            fin>>temp.grade[2];
            the.push_back(temp);         
        }  
        c_id=the[the.size()-1].id+1;
        fin.close();   
    }
    else
    {
        ofstream fout("students.txt");
        fout.close();
        cout << "There are no students!!" << endl;
        c_id=1;
        input(the);
    }
}


void sreacrh(vector <student> the)
{
    int n,id,f=0, age;
    string c,str;
    cout <<"Search with\n 1.ID\n 2.name\n 3.sex\n 4.age\n";
    cin >>n;
    switch (n)
    {
        case 1:
            cout << "enter search id:\t";
            if(cin >> id)
            {
                for (size_t i = 0; i < the.size(); i++)
                {
                    if(the[i].id==id)
                    {
                        cout << "student found:\n";
                        the[i].output();
                        break;
                    }
                    else if(i==the.size()-1)
                    {
                        cout <<"student not found\n";
                    }
                }
            }
            else
            {
                cout << "Invalid Input." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            break;
        case 2:
            cout << "enter search string:\t";
            cin >> c;
            transform(c.begin(), c.end(), c.begin(), ::tolower);
            for (size_t i = 0; i < the.size(); i++)
            {
                str=the[i].name.substr(0,c.length());
                transform(str.begin(), str.end(), str.begin(), ::tolower);
                if(str==c)
                {
                    the[i].output();
                    f++;                        
                }
                else if(i==the.size()-1&&f==0)
                {
                    cout <<"students not found\n";
                    break;
                }
            }
            break;
        case 3:
            cout << "enter search sex(m/f):\t";
            cin >> c;
            transform(c.begin(), c.end(), c.begin(), ::tolower);
            for (size_t i = 0; i < the.size(); i++)
            {
                str=the[i].sex;
                transform(str.begin(), str.end(), str.begin(), ::tolower);
                if(str==c)
                {
                    the[i].output();
                    f++;                        
                }
                else if(i==the.size()-1&&f==0)
                {
                    cout <<"students not found\n";
                    break;
                }
            }
            break;
        case 4:
            cout << "enter search age:\t";
            if(cin >> age)
            {
                for (size_t i = 0; i < the.size(); i++)
                {
                    if(the[i].age==age)
                    {
                        the[i].output();
                        f++; 
                    }
                    else if(i==the.size()-1 && f==0)
                    {
                        cout <<"student not found\n";
                    }
                }
            }
            else
            {
                cout << "Invalid Input." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            
            break;
        
        default:
            cout << "Invalid Input." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
    }
}

void edit(vector<student> &the)
{
    int id, index=-1;
    do
    {
        cout << "enter search id:\t";
        if (cin >> id)
        {
            for (size_t i = 0; i < the.size(); i++)
            {
                if(the[i].id==id)
                {
                    cout << "student found:\n";
                    index=i;
                    break;
                }
                else if(i==the.size()-1)
                {
                    cout <<"student not found\n";
                }
            }
        }
        else
        {
            cout << "Invalid Input." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    }while (id!=0 && index==-1);
    
    if (id!=0)
    {
        cout << "1.editi name " << endl;
        cout << "2.editi age " << endl;
        cout << "3.editi sex" << endl;
        cout << "4. editi grade" << endl;
        cout << "enter ID:" << endl;
        cin >> the[index].id;
        the[index].get_name();
        the[index].get_age();
        the[index].get_sex();
        the[index].get_grade();
        save_books(the);
    }
    else
    {
        cout << "cancled" <<endl;
    }
}
int main()
{
    int c;
    vector <student> stud;
    load_book(stud);
    do
    {
        cout <<"1.add\n" << "2.display\n" << "3.search\n" <<"4.editi\n" <<"5.Exiti" <<endl;
        cin >>c;
        switch (c)
        {
            case 1:
                system("clear");
                input(stud);
                break;
            case 2:
                system("clear");
                for (size_t i = 0; i < stud.size(); i++)
                {
                    stud[i].output();
                }
                break;
            case 3:
                system("clear");
                sreacrh(stud);
                break;
            case 4:
                system("clear");
                edit(stud);
                break;
            case 5:
                exit(0);
                break;
            default:
                cout << "Invalid Input." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }
    } while (true);
    
}