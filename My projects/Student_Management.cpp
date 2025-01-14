#include<iostream>
#include<string>
using namespace std;
struct Student
{
    string name;
    string id;
    string age;
    string section;
    float totalFee;
    float paidFee;
    float remainingFee;
    float marksObtained;
    float totalMarks;
    int totalDays;
    int daysPresent;
    int registeredHours;
    float scholarshipPercentage;
    float attendancePercentage;
};
int studentCount=0;
Student students[100];
bool login()
{
    string password="123";
    string login_Password;
    while(true)
    {
        cout<<"\n ENTER LOGIN PASSWORD : ";
        cin>>login_Password;
        if(login_Password==password)
        {
            cout<<"\n LOGIN  SUCCESSFUL";
            return true;
        }
        else
        {
            cout<<"\n Login failed  Please try again ";
        }
    }
}
void addFeeDetails()
{
    if(studentCount==0)
    {
        cout<<"\n No students found  Please add students first ";
        return;
    }
    string id;
    cout<<"\n Enter student ID to add fee details: ";
    cin>>id;
    for(int i=0;i<studentCount;i++)
    {
        if(students[i].id==id)
        {
            int pf=4,ict=3,discrete=3,english=3,physics=3,calculus=3;
            int creditHours[]={pf,ict,discrete,english,physics,calculus};
            string subjects[]={"Programming Fundamentals","ICT","Discrete Structures","English","Applied Physics","Pre-Calculus"};
            float costPerCreditHour=7800;
            float registrationFee=30000;
            float totalFee=registrationFee;
            int registeredHours=0;
            cout<<"\n Select courses to register: ";
            for(int j=0;j<6;j++)
            {
                char choice;
                cout<<"\n Do you want to register for "<<subjects[j]<<"("<<creditHours[j]<<"credit hours)?(y/n):";
                cin>>choice;
                if(choice=='y'||choice=='Y')
                {
                    registeredHours=registeredHours+creditHours[j];
                    totalFee=totalFee+creditHours[j]*costPerCreditHour;
                }
            }
            students[i].registeredHours=registeredHours;
            students[i].totalFee=totalFee;
            students[i].paidFee=0;            
            students[i].remainingFee=totalFee; 
            cout<<"\n Fee details added successfully! ";
            return;
        }
    }
    cout<<"\n Student not found ";
}
void displayFeeDetails()
{
    if(studentCount==0)
    {
        cout<<"\n No students found. Please add students first ";
        return;
    }
    string id;
    cout<<"\n Enter student ID to display fee details: ";
    cin>>id;
    for(int i=0;i<studentCount;i++)
    {
        if(students[i].id==id)
        {
            cout<<"\n Fee details for student ID "<<id<<":";
            cout<<"\n Registered Hours: "<<students[i].registeredHours;
            cout<<"\n Total Fee: "<<students[i].totalFee;
            cout<<"\n Paid Fee: "<<students[i].paidFee;
            cout<<"\n Remaining Fee: "<<students[i].remainingFee;
            return;
        }
    }
    cout<<"\n Student not found or fee details not updated ";
}
void addStudent()
{
    if(studentCount>=100)
    {
        cout<<"\n Cannot add more students  limit reached ";
        return;
    }
    cout<<"\n Enter student name: ";
    cin.ignore();
    getline(cin, students[studentCount].name);
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
        cout<<"\n No data found ";
        return;
    }
    string id;
    cout<<"\n Enter student ID to edit: ";
    cin>>id;
    for(int i=0;i<studentCount;i++)
    {
        if(students[i].id==id)
        {
            cout<<"\n Enter new student name: ";
            cin.ignore();
            getline(cin,students[i].name);
            cout<<"\n Enter new student age: ";
            cin>>students[i].age;
            cout<<"\n Enter new student section: ";
            cin>>students[i].section;
            cout<<"\n Student details updated successfully!";
            return;
        }
    }
    cout<<"\n Student not found ";
}
void deleteStudent()
{
    if(studentCount==0)
    {
        cout<<"\n No data found ";
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
    cout<<"\n Student not found ";
}
void searchStudent()
{
    if(studentCount==0)
    {
        cout<<"\n No data found ";
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
    cout<<"\n Student not found ";
}
void addScholarshipDetails()
{
    if(studentCount==0)
    {
        cout<<"\n No students found Please add students first ";
        return;
    }
    string id;
    cout<<"\n Enter student ID to add scholarship details: ";
    cin>>id;
    for(int i=0;i<studentCount;i++)
    {
        if(students[i].id==id)
        {
            cout<<"\n Enter marks obtained: ";
            cin>>students[i].marksObtained;
            cout<<"Enter total marks: ";
            cin>>students[i].totalMarks;
            float percentage=(students[i].marksObtained/students[i].totalMarks)*100;
            if(percentage>80)
            {
                students[i].scholarshipPercentage=100;
            }
            else if(percentage>=75)
            {
                students[i].scholarshipPercentage=50;
            }
            else if(percentage>=70)
            {
                students[i].scholarshipPercentage=25;
            }
            else
            {
                students[i].scholarshipPercentage=0;
            }
            float discount=(students[i].scholarshipPercentage/100)*students[i].totalFee;
            students[i].remainingFee=students[i].totalFee-discount;
            cout<<"\n Scholarship details added successfully! ";
            return;
        }
    }
    cout<<"\n Student not found ";
}
void displayScholarshipDetails()
{
    if(studentCount==0)
    {
        cout<<"\n No students found  Please add students first ";
        return;
    }
    string id;
    cout<<"\n Enter student ID to display scholarship details: ";
    cin>>id;
    for(int i=0;i<studentCount;i++)
    {
        if(students[i].id==id)
        {
            cout<<"\n Scholarship details for student ID "<<id<<":";
            cout<<"\n Total Fee: "<<students[i].totalFee;
            cout<<"\n Scholarship Percentage: "<<students[i].scholarshipPercentage<<"%";
            cout<<"\n Fee after Scholarship: "<<students[i].remainingFee;
            return;
        }
    }
    cout<<"\n Student not found or scholarship details not updated ";
}
void addAttendance()
{
    if(studentCount==0)
    {
        cout<<"\n No students found  Please add students first ";
        return;
    }
    string id;
    cout<<"\n Enter student ID to add attendance details: ";
    cin>>id;
   for(int i=0;i<studentCount;i++)
    {
        if(students[i].id==id)
        {
            cout<<"\n Enter total number of days: ";
            cin>>students[i].totalDays;
            cout<<"Enter number of days present: ";
            cin>>students[i].daysPresent;
            if(students[i].daysPresent>students[i].totalDays)
            {
                cout<<"Days present cannot exceed total days  Please enter correct values ";
                return;
            }
            students[i].attendancePercentage=(static_cast<float>(students[i].daysPresent)/students[i].totalDays)*100;
            cout<<"\n Attendance details added successfully! ";
            return;
        }
    }
    cout<<"\n Student not found ";
}
void displayAttendance()
{
    if(studentCount==0)
    {
        cout<<"\n No students found. Please add students first. ";
        return;
    }
    string id;
    cout<<"\n Enter student ID to display attendance details: ";
    cin>>id;
    for(int i=0;i<studentCount;i++)
    {
        if(students[i].id==id)
        {
            cout<<"\n Attendance details for student ID "<<id<<":";
            cout<<"\n Total Days: "<<students[i].totalDays;
            cout<<"\n Days Present: "<<students[i].daysPresent;
            cout<<"\n Attendance Percentage: "<<students[i].attendancePercentage<<"%";
            return;
        }
    }
    cout<<"\n Student not found or attendance details not updated ";
}

void displayAllStudents()
{
    if(studentCount==0)
    {
        cout<<"\n No students to display ";
        return;
    }
    for(int i=0;i<studentCount;i++)
    {
        cout<<"\n-------------------------";
        cout<<"\n Student "<<(i+1)<<" : ";
        cout<<"\n Name: "<<students[i].name;
        cout<<"\n ID: "<<students[i].id;
        cout<<"\n Age: "<<students[i].age;
        cout<<"\n Section: "<<students[i].section;
        cout<<"\n -------------------------";
    }
}
void studentMenu()
{
    cout<<"\n______________________________________";
    cout<<"\n|   |   STUDENT MANAGEMENT SYSTEM    |";
    cout<<"\n|___|________________________________|";
    cout<<"\n|   |                                |";
    cout<<"\n| 1 |   Add Student                  |";
    cout<<"\n| 2 |   Edit Student                 |";
    cout<<"\n| 3 |   Delete Student               |";
    cout<<"\n| 4 |   Search Student               |";
    cout<<"\n| 5 |   Display All Students         |";
    cout<<"\n| 6 |   Add Fee Details              |";
    cout<<"\n| 7 |   Display Fee Details          |";
    cout<<"\n| 8 |   Add Scholarship Details      |";
    cout<<"\n| 9 |   Display Scholarship Details  |";
    cout<<"\n| 10|   Add Attendance               |";
    cout<<"\n| 11|   Display Attendance           |";
    cout<<"\n| 0 |   Exit                         |";
    cout<<"\n|___|________________________________|";
    cout<<"\n Enter your Choice: ";
}
int main()
{
    if(!login())
        return 0;
    while(true)
    {
        studentMenu();
        string studentChoice;
        cin>>studentChoice;
        if(studentChoice=="1")
        {
            addStudent();
        }
        else if(studentChoice=="2")
        {
            editStudent();
        }
        else if(studentChoice=="3")
        {
            deleteStudent();
        }
        else if(studentChoice=="4")
        {
            searchStudent();
        }
        else if(studentChoice=="5")
        {
            displayAllStudents();
        }
        else if(studentChoice=="6")
        {
            addFeeDetails();
        }
        else if(studentChoice=="7")
        {
            displayFeeDetails();
        }
        else if(studentChoice=="8")
        {
            addScholarshipDetails();
        }
        else if(studentChoice=="9")
        {
            displayScholarshipDetails();
        }
        else if(studentChoice=="10")
        {
            addAttendance();
        }
        else if(studentChoice=="11")
        {
            displayAttendance();
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
    return 0;
}
