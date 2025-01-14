#include<iostream>
using namespace std;
bool login()
 {  
    string password="123";  
    string login_Password;
    while(true)
     {  
        cout<<"\n Enter login password  ";  
        cin>>login_Password;  
        if(login_Password==password) 
        {  
            cout<<"\n Login Successful ";  
            return true;  
        } 
        else
         {  
            cout<<"\n login failed please try again ";  
        }  
    }  
}  
void mainmenu()
{
  cout<<"\n\n_____________________________________________";
    cout<<"\n|        |                                  |";
    cout<<"\n|press 1 | for Manage Students              |";
    cout<<"\n|press 2 | for Manage Teacher               |";
    cout<<"\n|press 0 | for Exit                         |";
    cout<<"\n|        |                                  |";
    cout<<"\n|________|__________________________________|";
    cout<<"\n Enter your Choice : ";
}
void studentMenu()
{
  cout<<"\n\n___________________________________________";
    cout<<"\n|        |                                |";
    cout<<"\n|press 1 | for Add Student                |";
    cout<<"\n|press 2 | for Edit Student               |";
    cout<<"\n|press 3 | for Delete Student             |";
    cout<<"\n|press 4 | for Search Student             |";
    cout<<"\n|press 5 | for Display All Students       |";
    cout<<"\n|press 0 | for Back                       |";
    cout<<"\n|        |                                |";
    cout<<"\n|________|________________________________|";
    cout<<"\n Enter your Choice : ";
}
void teacherMenu()
{
    cout<<"\n\n ____________________________________";
    cout<<"\n|   |                                |";
    cout<<"\n| 1 |   Add Teacher                  |";
    cout<<"\n| 2 |   Edit Teacher                 |";
    cout<<"\n| 3 |   Delete Teacher               |";
    cout<<"\n| 4 |   Search Teacher               |";
    cout<<"\n| 5 |   Display All Teachers         |";
    cout<<"\n| 0 |   Back                         |";
    cout<<"\n|   |                                |";
    cout<<"\n|  _|________________________________|_";
    cout<<"\n Enter your Choice : ";
}
void addTeacher(int teacherCount,string teacherName[],string teacherID[],string teacherAge[])
{
    if(teacherCount>=100)
    {
        cout<<"\n Cannot add more teachers limit reached";
        return;
    }
    cout<<"\n Enter teacher name: ";
    cin.ignore();
    getline(cin,teacherName[teacherCount]);
    cout<<"\n Enter teacher ID: ";
    cin>>teacherID[teacherCount];
    cout<<"\n Enter teacher age: ";
    cin>>teacherAge[teacherCount];
    teacherCount++;
    cout<<"\n Teacher added successfully!";
}
void editTeacher(int teacherCount,string teacherName[],string teacherID[],string teacherAge[])
{
    string id;
    cout<<"\n Enter teacher ID to edit: ";
    cin>>id;
    for(int i=0;i<teacherCount;i++)
    {
        if(teacherID[i]==id)
        {
            cout<<"\n Enter new teacher name: ";
            cin.ignore();
            getline(cin,teacherName[i]);
            cout<<"\n Enter new teacher age: ";
            cin>>teacherAge[i];
            cout<<"\n Teacher details updated successfully!";
            return;
        }
    }
    cout<<"\n Teacher not found";
}
void deleteTeacher(int teacherCount,string teacherName[],string teacherID[],string teacherAge[])
{
    string id;
    cout<<"\n Enter teacher ID to delete: ";
    cin>>id;
    for(int i=0;i<teacherCount;i++)
    {
        if(teacherID[i]==id)
        {
         for(int j=i;j<teacherCount-1;j++)
            {
            teacherName[j]=teacherName[j+1];
            teacherID[j]=teacherID[j+1];
            teacherAge[j]=teacherAge[j+1];
                        }
         teacherCount--;
         cout<<"\n Teacher deleted successfully!";
         return;
        }
    }
    cout<<"\n Teacher not found";
}
void searchTeacher(int teacherCount,string teacherName[],string teacherID[],string teacherAge[])
{
    string id;
    cout<<"\n Enter teacher ID to search: ";
    cin>>id;
    for(int i=0;i<teacherCount;i++)
    {
        if(teacherID[i]==id)
        {
          cout<<"\n Teacher found: ";
         cout<<"\n Name: "<<teacherName[i];
          cout<<"\n ID: "<<teacherID[i];
          cout<<"\n Age: "<<teacherAge[i];
       return;
      }
 }
   cout<<"\n Teacher not found";
}

void displayAllTeachers(int teacherCount,string teacherName[],string teacherID[],string teacherAge[])
{
    if(teacherCount==0)
    {
        cout<<"\n No teachers to display";
        return;
    }
    for(int i=0;i<teacherCount;i++)
    {
        cout<<"\n----------------------------\n";
        cout<<"\n Teacher "<<(i+1)<<": ";
        cout<<"\n Name: "<<teacherName[i];
        cout<<"\n ID: "<<teacherID[i];
        cout<<"\n Age: "<<teacherAge[i];
        cout<<"\n----------------------------\n";
    }
}
void addStudent(int &studentCount,string studentName[],string studentID[],string studentAge[],string studentSection[])
{
    if(studentCount>=100)
    {
        cout<<"\n Cannot add more students, limit reached";
        return;
    }
    cout<<"\n Enter student name: ";
    cin.ignore();
    getline(cin,studentName[studentCount]);
    cout<<"\n Enter student ID: ";
    cin>>studentID[studentCount];
    cout<<"\n Enter student age: ";
    cin>>studentAge[studentCount];
    cout<<"\n Enter student section: ";
    cin>>studentSection[studentCount];
    studentCount++;
    cout<<"\n Student added successfully!";
    return;
}
void editStudent(int studentCount,string studentName[],string studentID[],string studentAge[],string studentSection[])
{
    string id;
    cout<<"\n Enter student ID to edit: ";
    cin>>id;
    for(int i=0;i<studentCount;i++)
    {
     if(studentID[i]==id)
    {
         cout<<"\n Enter new student name: ";
      cin.ignore();
      getline(cin,studentName[i]);
      cout<<"\n Enter new student age: ";
       cin>>studentAge[i];
       cout<<"\n Enter new student section: ";
       cin>>studentSection[i];
        cout<<"\n Student details updated successfully!";
                    return;
        }
    }
    cout<<"\n Student not found";
}
void deleteStudent(int student_Count, string studentName[], string studentID[], string studentAge[], string studentSection[])
{
    string id;
    cout<<"\n Enter student ID to delete: ";
    cin>>id;
    for(int i=0;i<student_Count;i++)
    {
        if(studentID[i]==id)
        {
            for(int j=i;j<student_Count-1;j++)
            {
          studentName[j]=studentName[j+1];
         studentID[j]=studentID[j+1];
            studentAge[j]=studentAge[j+1];
           studentSection[j]=studentSection[j+1];
            }
            student_Count--;
            cout<<"\n Student deleted successfully!";
            return;
        }
    }
    cout<<"\n Student not found";
}
void searchStudent(int studentCount, string studentName[],string studentID[],string studentAge[],string studentSection[])
{
    string id;
    cout<<"\n Enter student ID to search: ";
    cin>>id;
    for(int i=0;i<studentCount;i++)
    {
        if(studentID[i]==id)
        {
            cout<<"\n Student found: ";
            cout<<"\n Name: "<<studentName[i];
            cout<<"\n ID: "<<studentID[i];
            cout<<"\n Age: "<<studentAge[i];
            cout<<"\n Section: "<<studentSection[i];
            return;
        }
    }
    cout<<"\n Student not found";
}
void displayAllStudents(int studentCount,string studentName[],string studentID[],string studentAge[],string studentSection[])
{
    if(studentCount==0)
    {
        cout<<"\n No students to display";
        return;
    }
    for(int i=0;i<studentCount;i++)
    {
        cout<<"\n-------------------------\n";
        cout<<"\n Student "<<(i+1)<<" : ";
        cout<<"\n Name: "<<studentName[i];
        cout<<"\n ID: "<<studentID[i];
        cout<<"\n Age: "<<studentAge[i];
        cout<<"\n Section: "<<studentSection[i];
        cout<<"\n-------------------------\n";
    }
}
int main()
{
    if(!login())
        exit(0);
    int studentCount=0;
    const int maxStudents =100;
    string studentName[maxStudents];
    string studentID[maxStudents];
    string studentAge[maxStudents];
    string studentSection[maxStudents];
    const int maxTeachers = 100;
    int teacherCount = 0;
    string teacherName[maxTeachers];
    string teacherID[maxTeachers];
    string teacherAge[maxTeachers];
    while (true)
    {
        mainmenu();
        string choice;
        cin>>choice;
        if(choice=="1")
        {
            while(true)
            {
                studentMenu();
                string studentChoice;
                cin>>studentChoice;
                if(studentChoice=="1")
                {
                    addStudent(studentCount,studentName,studentID,studentAge,studentSection);
                                   }
                else if(studentChoice=="2")
                {
                    editStudent(studentCount,studentName,studentID,studentAge,studentSection);
                }
                else if(studentChoice=="3")
                {
                    deleteStudent(studentCount,studentName,studentID,studentAge,studentSection);
                }
                else if(studentChoice=="4")
                {
                    searchStudent(studentCount,studentName,studentID,studentAge,studentSection);
                }
                else if(studentChoice=="5")
                {
                    displayAllStudents(studentCount,studentName,studentID,studentAge,studentSection);
                }
                else if(studentChoice=="0")
                {
                    break;
                }
                else
                {
                    cout<<"\n Invalid Option!";
                }
            }
        }
        else if(choice=="2")
        {
            while(true)
            {
                teacherMenu();
                string teacherChoice;
                cin>>teacherChoice;
                if(teacherChoice=="1")
                {
                    addTeacher(teacherCount,teacherName,teacherID,teacherAge);
                }
                else if(teacherChoice=="2")
                {
                    editTeacher(teacherCount,teacherName,teacherID,teacherAge);
                }
                else if(teacherChoice=="3")
                {
                    deleteTeacher(teacherCount,teacherName,teacherID,teacherAge);
                }
                else if(teacherChoice=="4")
                {
                    searchTeacher(teacherCount,teacherName,teacherID,teacherAge);
                }
                else if(teacherChoice=="5")
                {
                    displayAllTeachers(teacherCount,teacherName,teacherID,teacherAge);
                }
                else if(teacherChoice=="0")
                {
                    break;
                }
                else
                {
                    cout<<"\n Invalid Option!";
                }
            }
        }
        else if(choice=="0")
        {
            cout<<"\n Thanks For Using!";
            break;
        }
        else
        {
            cout<<"\n Invalid Option!";
        }
    }
    return 0;
}