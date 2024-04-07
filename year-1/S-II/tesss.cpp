#include <iostream>
#include <fstream>
#include <string>
using namespace std;

   int numstud = 0;
struct student {
     int id,age;
     char sex;
     float mark[3];
     char name [30];
};


student *getdata(student s[100]){
      system("cls");
      fstream stud ("student.txt", ios::out | ios::app);
      int sizee;
      cout<< "how many students are there"<< endl;
      cin>> sizee;

       cout<< endl;
//stud << endl<< "ID"<< '\t'<< "NAME"<< '\t'<< "SEX"<<'\t'<< "MARK 1"<< '\t'<< "MARK 2"<< '\t'<< "MARK 3"<<endl;
     for (int i = numstud; i < (numstud + sizee); ++i)
     {
        cout<<"\tSTUDENT "<< i+1<<":"<<endl;
        cout << "id:"<<endl;
        cin>> s[i].id;
        cout<< "name"<<endl;
        cin>> s[i].name;
        cout<< "sex"<<endl;
        cin>> s[i].sex;
        for(int j = 0; j < 3; j++)
        {
      cout << "Enter mark: ";
      cin >> s[i].mark[j];
        }
   cout<< endl;
     }

for (int i=numstud;i<sizee+numstud;i++){
        stud<< s[i].id << '\t'<< s[i].name << '\t'<<s[i].sex <<'\t';//<<s[i].mark[1]<< '\t'<<s[i].mark[2]<<'\t'<<s[i].mark[3]<<endl;
        for(int j=0;j<3;j++){
      stud<< s[i].mark[j]<<"\t";
     }
     stud<< endl;

}
   numstud+=sizee;

   stud.close();
   return s;


}

void display (student s[100]){
     system("cls");
     fstream stud ("student.txt", ios::out | ios::in | ios::app);
     string sl;
     while (getline (stud, sl)){
        cout<< sl << endl;}
        stud.close();
     }
void searchs(student *s, string searchkey){
    fstream stud ("student.txt", ios::out | ios::in | ios::app);
    string sl;
    while(getline(stud,sl)){
        if(sl.find(searchkey)!= string::npos){
        cout<<"Id\t NAME \t SEX\t MARK 1\t 2\t MARK 3\t"<<endl;
        cout<<sl<<endl;
        }
    }
    stud.close();
}
void EDIT(student s[100]){

    system("cls");
    int ID,choice;
    fstream stud("students.txt", ios::app);
    
    if(stud.is_open())
    {
        for(int i=0; !stud.eof(); i++)
        {
            stud>> s[i].id >> s[i].name>> s[i].sex ;//<<s[i].mark[1]<< '\t'<<s[i].mark[2]<<'\t'<<s[i].mark[3]<<endl;
            for(int j=0;j<3;j++){
          stud>> s[i].mark[j];
         }
        }
    }
    cout<<"please enter student ID:";
    cin>>ID;
    for(int i=0;i<numstud;i++){

                     if(s[i].id==ID){

            cout<<"which entity do you want to update:"<<endl;
            cout<<"for name press 1:"<<endl;
            cout<<"for ID press 2:"<<endl;
            cout<<"for age press 3:"<<endl;
            cout<<"for mark press 4:"<<endl;
            cin>>choice;
            switch(choice)
            {
            case(1):
                cout<<"enter the new name:";
                cin>>s[i].name;
                break;
            case(2):
                cout<<"enter the new ID:";
                cin>>s[i].id;
                break;
            case(3):
                cout<<"enter the new age:";
                cin>>s[i].age;
                break;
            case(4):
                cout<<"enter the mark:";
                for(int j=0;j<3;j++){
                cin>>s[i].mark[j];}
                break;
            default:
                cout<<"WRONG ENTRY!!";
                break;
            }
            cout<<"you can see the edited data on your file."<<endl;
               break;
    }
    else
        {
        cout<<"NOT FOUND, TRY AGAIN!!";
    break;
    }

             }


     stud<<"\nID\t\tNAME\t\tAGE\t\tMARK 1\t\tMARK 2\t\t MARK 3"<<endl;
      for(int i=0;i<numstud;i++){
    stud<<s[i].id<<"\t\t"<<s[i].name<<"\t\t"<<s[i].age<<"\t\t";
 for(int j=0;j<3;j++){
            stud<<s[i].mark[j]<<"\t\t";
             }
             stud<<"\n";
      }
      stud.close();
}

void menu (){
    system("cls");
    fstream stud("student.txt", ios::app | ios::out);
    if(stud.is_open()){
        cout<<" file opened successfully.";
    }
    else{
        cout<<"could't open";
    }
while(true){
    student *stu;
    student s[100];
    char choice;
    m:
    cout<<"\n\t\tMENU\n"<<endl;
    cout<<" 1.ADD"<<endl;
    cout<<" 2.DISPLAY"<<endl;
    cout<<" 3.SEARCH"<<endl;
    cout<< "4.EDIT"<<endl;
    cin>>choice;
    switch(choice)
    {

    case('1'):
        stu=getdata(s);
        goto m;
        break;
    case('2'):
        display(stu);
        break;
    case('3'):{
            string searchkey;
            cout<<"Enter search key(By name):";
            cin.ignore();
            getline(cin,searchkey);
            searchs(s,searchkey);
            break;}
    case('4'):{
        /*string word;
        cout<< "enter the name of the student you want edit";
        cin.ignore();
        getline(cin,word);*/
        EDIT(s);
        break;}
    default:
        cout<<" YOU PRESSED WRONG KEY!!!";
        break;

    }
    }
}


int main (){
menu();
return 0;
}