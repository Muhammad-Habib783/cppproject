#include <iostream>
#include <string>
using namespace std;
struct Teacher
{
    string name;
    string id;
    string age;
};
struct Student
{
    string name;
    string id;
    string age;
    string section;
};
struct Fee
{
    string studentID;
    float totalFee;
    float paidFee;
    float remainingFee;
};
struct Result
{
    string studentID;
    float marksObtained;
    float totalMarks;
};
struct Attendence
{
  string studentname;
  string  studentid;
  string section;
};
int studentCount=0;
int teacherCount=0;
Student students[100];
Teacher teachers[10];
Result result;
Fee fee;
Attendence attencence;
bool login()
{
    string password ="123";
    string login_Password;
    while(true)
    {
        cout<<"\n Enter login password: ";
        cin>>login_Password;
        if(login_Password==password)
        {
            cout<<"\n Login Successful";
            return true;
        }
        else
        {
            cout<<"\n Login failed Please try again.";
        }
    }
}
void MainMenu()
{
    cout<<"\n _________________________________";
    cout<<"\n |   School Management System    |";
    cout<<"\n |_______________________________|";
    cout<<"\n |press 1: to manage students    |";
    cout<<"\n |press 2: to manage teachers    |";
    cout<<"\n |press 3: to manage fee         |";
    cout<<"\n |press 4: to manage result      |";
    cout<<"\n |press 5: to manage attendence  |";
    cout<<"\n |press 0: to exit               |";
    cout<<"\n |_______________________________|";
    cout<<"\n | Enter your choice:            |";
    cout<<"\n |_______________________________|";
}
void StudentMenu()
{
    cout<<"\n _________________________________";
    cout<<"\n |   Student Management          |";
    cout<<"\n |_______________________________|";
    cout<<"\n |press 1: to add student        |";
    cout<<"\n |press 2: to edit student       |";
    cout<<"\n |press 3: to delete student     |";
    cout<<"\n |press 4: to search student     |";
    cout<<"\n |press 5: to display all student|";
    cout<<"\n |press 0: to back               |";
    cout<<"\n |_______________________________|";
    cout<<"\n | Enter your choice:            |";
    cout<<"\n |_______________________________|";
}
void TeacherMenu()
{
    cout<<"\n _________________________________";
    cout<<"\n |   Teacher Management          |";
    cout<<"\n |_______________________________|";
    cout<<"\n |press 1: to add teacher        |";
    cout<<"\n |press 2: to edit teacher       |";
    cout<<"\n |press 3: to delete teacher     |";
    cout<<"\n |press 4: to search teacher     |";
    cout<<"\n |press 5: to display all teacher|";
    cout<<"\n |press 0: to back               |";
    cout<<"\n |_______________________________|";
    cout<<"\n | Enter your choice:            |";
    cout<<"\n |_______________________________|";
}   
void FeeMenu()
{
    cout<<"\n _________________________________";
    cout<<"\n |   Fee Management              |";
    cout<<"\n |_______________________________|";
    cout<<"\n |press 1: to add fee            |";
    cout<<"\n |press 2: to edit fee           |";
    cout<<"\n |press 3: to delete fee         |";
    cout<<"\n |press 4: to search fee         |";
    cout<<"\n |press 5: to display all fee    |";
    cout<<"\n |press 0: to back               |";
    cout<<"\n |_______________________________|";
    cout<<"\n | Enter your choice:            |";
    cout<<"\n |_______________________________|";
}   
void ResultMenu()
{
    cout<<"\n _________________________________";
    cout<<"\n |   Result Management           |";
    cout<<"\n |_______________________________|";
    cout<<"\n |press 1: to add result         |";
    cout<<"\n |press 2: to edit result        |";
    cout<<"\n |press 3: to delete result      |";
    cout<<"\n |press 4: to search result      |";
    cout<<"\n |press 5: to display all result |";
    cout<<"\n |press 0: to back               |";
    cout<<"\n |_______________________________|";
    cout<<"\n | Enter your choice:            |";
    cout<<"\n |_______________________________|";
}   
void AttendenceMenu()
{
    cout<<"\n ____________________________________";
    cout<<"\n |   Attendence Management          |";
    cout<<"\n |__________________________________|";
    cout<<"\n |press 1: to add attendence        |";
    cout<<"\n |press 2: to edit attendence       |";
    cout<<"\n |press 3: to delete attendence     |";
    cout<<"\n |press 4: to search attendence     |";
    cout<<"\n |press 5: to display all attendence|";
    cout<<"\n |press 0: to back                  |";
    cout<<"\n |__________________________________|";
    cout<<"\n | Enter your choice:               |";
    cout<<"\n |__________________________________|";
}   
void addTeacher()
{
    if(teacherCount>=10)
    {
        cout<<"\n Cannot add more teachers limit reached";
        return;
    }
    cout<<"\n Enter teacher name: ";
    cin.ignore();
    getline(cin, teachers[teacherCount].name);
    cout<<"\n Enter teacher ID: ";
    cin>>teachers[teacherCount].id;
    cout<<"\n Enter teacher age: ";
    cin>>teachers[teacherCount].age;
    teacherCount++;
    cout<<"\n Teacher added successfully!";
}
void editTeacher()
{
    if(teacherCount==0)
    {
        cout<<"\n No data found.\n";
        return;
    }
    string id;
    cout<<"\n Enter teacher ID to edit: ";
    cin>>id;
    for(int i=0;i<teacherCount;i++)
    {
        if(teachers[i].id==id)
        {
            cout<<"\n Enter new teacher name: ";
            cin.ignore();
            getline(cin, teachers[i].name);
            cout<<"\n Enter new teacher age: ";
            cin>>teachers[i].age;
            cout<<"\n Teacher details updated successfully!";
            return;
        }
    }
    cout<<"\n Teacher not found";
}
void deleteTeacher()
{
    if (teacherCount==0)
    {
        cout<<"\n No data found for delete teacher ";
        return;
    }
    string id;
    cout<<"\n Enter teacher ID to delete: ";
    cin>>id;
    for(int i=0;i<teacherCount;i++)
    {
        if(teachers[i].id==id)
        {
            for(int j=i;j<teacherCount-1;j++)
            {
                teachers[j]=teachers[j+1];
            }
            teacherCount--;
            cout<<"\n Teacher deleted successfully!";
            return;
        }
    }
    cout<<"Teacher not found";
}
void searchTeacher()
{

    if(teacherCount==0)
    {
        cout<<"\n No data found for search teacher";
        return;
    }
    string id;
    cout<<"\n Enter teacher ID to search: ";
    cin>>id;
    for(int i=0;i<teacherCount;i++)
    {
        if(teachers[i].id==id)
        {
            cout<<"\nteacher found:";
            cout<<"\nName: "<<teachers[i].name;
            cout<<"\nID: "<<teachers[i].id;
            cout<<"\nAge: "<<teachers[i].age;
            return;
        }
    }

    cout<<"\n teacher not found ";
}
void displayAllTeachers()
{
    if(teacherCount==0)
    {
        cout<<"\n No teachers to display";
        return;
    }
    for(int i=0;i<teacherCount;i++)
    {
        cout<<"\n----------------------------";
        cout<<"\n Teacher "<<(i+1)<<" : ";
        cout<<"\n Name: "<<teachers[i].name;
        cout<<"\n ID: "<<teachers[i].id;
        cout<<"\n Age: "<<teachers[i].age;
        cout<<"\n----------------------------";
    }
}
void addStudent()
{
    if(studentCount>=100)
    {
        cout<<"\n Cannot add more students limit reached";
        return;
    }
    cout<<"\n Enter student name: ";
    cin.ignore();
    getline(cin,students[studentCount].name);
    cout<<"\n Enter student ID: ";
    cin>>students[studentCount].id;
    cout<<"\n Enter student age: ";
    cin>>students[studentCount].age;
    cout<<"\n Enter student section: ";
    cin>>students[studentCount].section;
    studentCount++;
    cout<<"\n Student added successfully!";
}
void editStudent()
{
    if(studentCount==0)
    {
        cout<<"\n no data found for edit";
        return;
    }
    string id;
    cout<<"\n Enter student ID to edit:";
    cin>>id;
    for(int i=0;i<studentCount;i++)
    {
        if(students[i].id==id)
        {
            cout<<"\n Enter new student name: ";
            cin.ignore();
            getline(cin, students[i].name);
            cout<<"\n Enter new student age: ";
            cin>>students[i].age;
            cout<<"\n Enter new student section: ";
            cin>>students[i].section;
            cout<<"\n Student details updated successfully!";
            return;
        }
    }
    cout<<"\n Student not found";
}
void deleteStudent()
{
    if(studentCount==0)
    {
        cout<<"\n no data found for delete";
        return;
    }
    string id;
    cout<<"\n Enter student ID to delete: ";
    cin>>id;
    for(int i=0;i<studentCount;i++)
    {
        if(students[i].id==id)
        {
            for(int j=i;j<studentCount-1;j++)
            {
                students[j]=students[j+1];
            }
            studentCount--;
            cout<<"\n Student deleted successfully!";
            return;
        }
    }
    cout<<"\n Student not found";
}
void searchStudent()
{
    if (studentCount==0)
    {
        cout<<" \n no data found  for search ";
        return;
    }
    string id;
    cout<<"\n Enter student ID to search: ";
    cin>>id;
    for(int i=0;i<studentCount;i++)
    {
        if(students[i].id==id)
        {
            cout<<"\n Student found: ";
            cout<<"\n Name: "<<students[i].name;
            cout<<"\n ID: "<<students[i].id;
            cout<<"\n Age: "<<students[i].age;
            cout<<"\n Section: "<<students[i].section;
            return;
        }
    }
    cout<<"\n Student not found";
}
void displayAllStudents()
{
    if(studentCount==0)
    {
        cout<<"\n No students to display";
        return;
    }
    for(int i=0;i<studentCount;i++)
    {
        cout<<"\n-------------------------";
        cout<<"\n Student "<< (i + 1) << " : ";
        cout<<"\n Name: "<< students[i].name;
        cout<<"\n ID: "<< students[i].id;
        cout<<"\n Age: "<< students[i].age;
        cout<<"\n Section: "<< students[i].section;
        cout<<"\n -------------------------";
    }
}
void addfee()
{

    cout<<"\n Enter student ID: ";
    cin>>fee.studentID;
    cout<<"\n Enter total fee: ";
    cin>>fee.totalFee;
    cout<<"\n Enter paid fee: ";
    cin>>fee.paidFee;
    fee.remainingFee=fee.totalFee-fee.paidFee;
    cout<<"\n Fee details added successfully!";
    cout<<"\n Remaining fee: "<<fee.remainingFee;
}
void displayfee()
{
    if(studentCount==0)
    {
        cout<<"no data found "<<endl;
        return;
    }
    cout<<"\n Enter student ID to display fee details: ";
    cin>>fee.studentID;
    cout<<"\n Total fee: "<<fee.totalFee;
    cout<<"\n Paid fee: "<<fee.paidFee;
    cout<<"\n Remaining fee: "<<fee.remainingFee;
}
void addresult()
{

    cout<<"\n Enter student ID: ";
    cin>>result.studentID;
    cout<<"\n Enter marks obtained: ";
    cin>>result.marksObtained;
    cout<<"\n Enter total marks: ";
    cin>>result.totalMarks;
    cout<<"\n Result added successfully!";
    cout<<"\n Percentage: "<<(result.marksObtained/result.totalMarks)*100<<"%";
 if((result.marksObtained/result.totalMarks)*100>80)
    {
        cout<<"\n Scholarship awarded!";
    }
    else
    {
        cout<<"\n you have lose the scholarship ";
    }
}
void displayresult()
{
    if (studentCount==0)
    {
        cout<<"\n NO  Data Found For Display ";
        return;
    }
    cout<<"\n Enter student ID to display result: ";
    cin>>result.studentID;
    cout<<"\n Marks obtained: "<<result.marksObtained;
    cout<<"\n Total marks: "<<result.totalMarks;
    cout<<"\n Percentage: "<<(result.marksObtained/result.totalMarks)*100<<"%";
}
void addattencence()
{
    cout<<"\n Enter student name: ";
    cin.ignore();
    getline(cin,attencence.studentname);
    cout<<"\n Enter student ID: ";
    cin>>attencence.studentid;
    cout<<"\n Enter student section: ";
    cin>>attencence.section;
    cout<<"\n Attendance added successfully!";
   int totalClasses,attendedClasses;
 cout<<"\n Enter total number of classes: ";
 cin>>totalClasses;
 cout<<"\n Enter number of classes attended: ";
 cin>>attendedClasses;
 float attendancePercentage=((float)attendedClasses/totalClasses)*100;
 cout<<"\n Attendance Percentage: "<<attendancePercentage<<"%";
}
void displayattencence()
{
    if(studentCount==0)
    {
        cout<<"\n no data found for student attendence ";
        return;
    }
    cout<<"\n Enter student ID to display result: ";
    cin>>attencence.studentid;
    cout<<"\n Student name: "<<attencence.studentname;
    cout<<"\n Student ID: "<<attencence.studentid;
    cout<<"\n Section: "<<attencence.section;
}
int main()
{
    if(!login())
        return 0;
    while(true)
    {
        MainMenu();
        int choice;
        cin>>choice;
        if(choice==1)
        {
            while(true)
            {
                StudentMenu();
                int studentChoice;
                cin>>studentChoice;
                if(studentChoice==1)
                {
                    addStudent();
                }
                else if(studentChoice==2)
                {
                    editStudent();
                }
                else if(studentChoice==3)
                {
                    deleteStudent();
                }
                else if(studentChoice==4)
                {
                    searchStudent();
                }
                else if(studentChoice==5)
                {
                    displayAllStudents();
                }
                else if(studentChoice==0)
                {
                    break;
                }
                else
                {
                    cout<<"\n Invalid Option!";
                }
            }
        }
        else if(choice==2)
        {
            while(true)
            {
                TeacherMenu();
                int teacherChoice;
                cin>>teacherChoice;
                if(teacherChoice==1)
                {
                    addTeacher();
                }
                else if(teacherChoice==2)
                {
                    editTeacher();
                }
                else if(teacherChoice==3)
                {
                    deleteTeacher();
                }
                else if(teacherChoice==4)
                {
                    searchTeacher();
                }
                else if(teacherChoice==5)
                {
                    displayAllTeachers();
                }
                else if(teacherChoice==0)
                {
                    break;
                }
                else
                {
                    cout<<"\n Invalid Option!";
                }
            }
        }
        else if(choice==3)
        {
            while(true)
            {
                FeeMenu();
                int feechoice;
                cin>>feechoice;
                if(feechoice==1)
                {
                    addfee();
                }
                else if(feechoice==2)
                {
                    displayfee();
                }
                else if(feechoice==0)
                {
                    break;
                }
                else
                {
                    cout<<"\n Invalid option ";
                }
            }
        }
        else if(choice==4)
        {
            while(true)
            {
                ResultMenu();
                int resultchoice;
                cin>>resultchoice;
                if(resultchoice==1)
                {
                    addresult();
                }
                else if(resultchoice==2)
                {
                    displayresult();
                }
                else if(resultchoice==0)
                {
                    break;
                }
                else
                {
                    cout<<"\n Invalid option ";
                }
            }
        }
        else if(choice==5)
        {
            while(true)
            {
                AttendenceMenu();
                int attencencechoice;
                cin>>attencencechoice;
                if(attencencechoice==1)
                {
                    addattencence();
                }
                else if(attencencechoice==2)
                {
                    displayattencence();
                }
                else if(attencencechoice==0)
                {
                    break;
                }
                else
                {
                    cout<<"\n invalid option ";
                }
            }
        }
        else if(choice==0)
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