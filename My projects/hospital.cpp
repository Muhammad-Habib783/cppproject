#include <iostream>
#include <string>

using namespace std;


const int MAX_PATIENTS = 1000;
const int MAX_DOCTORS = 100;
const int MAX_APPOINTMENTS = 1000;
const int MAX_BILLS = 10000;


struct Patient
{
    int id;
    string name;
    int age;
    string ailment;
};

struct Doctor
{
    int id;
    string name;
    int age;
    string specialization;
};

struct Billing
{
    string patientName;
    int patientID;
    int patientAge;
    string doctorName;
    int doctorID;
    double amount;
};

struct Appointment
{
    int appointmentID;
    int patientID;
    int doctorID;
    string date;
};

Patient patients[MAX_PATIENTS];
Doctor doctors[MAX_DOCTORS];
Appointment appointments[MAX_APPOINTMENTS];
Billing bills[MAX_BILLS];


int patientCount = 0;
int doctorCount = 0;
int appointmentCount = 0;
int billCount = 0;

bool authenticate(const string &correct_password)
{
    string input_password;

    cout << "Enter password: ";
    cin >> input_password;

    return correct_password == input_password;
}

void addPatient()
{
    if (patientCount >= MAX_PATIENTS)
    {
        cout << "Patient limit reached!" << endl;
        return;
    }
    Patient &patient = patients[patientCount++];
    cout << "Enter Patient ID: ";
    cin >> patient.id;
    cout << "Enter Patient Name: ";
    cin.ignore();
    getline(cin, patient.name);
    cout << "Enter Patient Age: ";
    cin >> patient.age;
    cout << "Enter Ailment: ";
    cin.ignore();
    getline(cin, patient.ailment);
    cout << "Patient added successfully!" << endl;
}

void addDoctor()
{
    if (doctorCount >= MAX_DOCTORS)
    {
        cout << "Doctor limit reached!" << endl;
        return;
    }
    Doctor &doctor = doctors[doctorCount++];
    cout << "Enter Doctor ID: ";
    cin >> doctor.id;
    cout << "Enter Doctor Name: ";
    cin.ignore();
    getline(cin, doctor.name);
    cout << "Enter Doctor Age: ";
    cin >> doctor.age;
    cout << "Enter Specialization: ";
    cin.ignore();
    getline(cin, doctor.specialization);
    cout << "Doctor added successfully!" << endl;
}

void addBilling()
{
    if (billCount >= MAX_BILLS)
    {
        cout << "Bill limit reached!" << endl;
        return;
    }
    Billing &bill = bills[billCount++];
    cout << "Enter Patient Name: ";
    cin.ignore();
    getline(cin, bill.patientName);
    cout << "Enter Patient ID: ";
    cin >> bill.patientID;
    cout << "Enter Patient Age: ";
    cin >> bill.patientAge;
    cout << "Enter Doctor Name: ";
    cin.ignore();
    getline(cin, bill.doctorName);
    cout << "Enter Doctor ID: ";
    cin >> bill.doctorID;
    cout << "Enter Amount: ";
    cin >> bill.amount;
    cout << "Bill added successfully!" << endl;
}

void addAppointment()
{
    if (appointmentCount >= MAX_APPOINTMENTS)
    {
        cout << "Appointment limit reached!" << endl;
        return;
    }
    Appointment &appointment = appointments[appointmentCount++];
    cout << "Enter Appointment ID: ";
    cin >> appointment.appointmentID;
    cout << "Enter Patient ID: ";
    cin >> appointment.patientID;
    cout << "Enter Doctor ID: ";
    cin >> appointment.doctorID;
    cout << "Enter Date (YYYY-MM-DD): ";
    cin.ignore();
    getline(cin, appointment.date);
    cout << "Appointment added successfully!" << endl;
}

void displayPatients()
{
    for (int i = 0; i < patientCount; ++i)
    {
        cout << "Patient ID: " << patients[i].id << endl;
        cout << "Name: " << patients[i].name << endl;
        cout << "Age: " << patients[i].age << endl;
        cout << "Ailment: " << patients[i].ailment << endl;
        cout << "-----------------" << endl;
    }
}

void displayDoctors()
{
    for (int i = 0; i < doctorCount; ++i)
    {
        cout << "Doctor ID: " << doctors[i].id << endl;
        cout << "Name: " << doctors[i].name << endl;
        cout << "Age: " << doctors[i].age << endl;
        cout << "Specialization: " << doctors[i].specialization << endl;
        cout << "-----------------" << endl;
    }
}

void displayBills()
{
    for (int i = 0; i < billCount; ++i)
    {
        cout << "Patient Name: " << bills[i].patientName << endl;
        cout << "Patient ID: " << bills[i].patientID << endl;
        cout << "Patient Age: " << bills[i].patientAge << endl;
        cout << "Doctor Name: " << bills[i].doctorName << endl;
        cout << "Doctor ID: " << bills[i].doctorID << endl;
        cout << "Amount: $" << bills[i].amount << endl;
        cout << "-----------------" << endl;
    }
}

void displayAppointments()
{
    for (int i = 0; i < appointmentCount; ++i)
    {
        cout << "Appointment ID: " << appointments[i].appointmentID << endl;
        cout << "Patient ID: " << appointments[i].patientID << endl;
        cout << "Doctor ID: " << appointments[i].doctorID << endl;
        cout << "Date: " << appointments[i].date << endl;
        cout << "-------------------------------" << endl;
    }
}

void searchPatient()
{
    int id;
    cout << "Enter Patient ID: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < patientCount; ++i)
    {
        if (patients[i].id == id)
        {
            cout << "Patient ID: " << patients[i].id << endl;
            cout << "Name: " << patients[i].name << endl;
            cout << "Age: " << patients[i].age << endl;
            cout << "Ailment: " << patients[i].ailment << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Patient not found!" << endl;
    }
}

void searchDoctor()
{
    int id;
    cout << "Enter Doctor ID: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < doctorCount; ++i)
    {
        if (doctors[i].id == id)
        {
            cout << "Doctor ID: " << doctors[i].id << endl;
            cout << "Name: " << doctors[i].name << endl;
            cout << "Age: " << doctors[i].age << endl;
            cout << "Specialization: " << doctors[i].specialization << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Doctor not found!" << endl;
    }
}

void searchBill()
{
    int id;
    cout << "Enter Patient ID: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < billCount; ++i)
    {
        if (bills[i].patientID == id)
        {
            cout << "Patient Name: " << bills[i].patientName << endl;
            cout << "Patient ID: " << bills[i].patientID << endl;
            cout << "Patient Age: " << bills[i].patientAge << endl;
            cout << "Doctor Name: " << bills[i].doctorName << endl;
            cout << "Doctor ID: " << bills[i].doctorID << endl;
            cout << "Amount: $" << bills[i].amount << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Bill not found!" << endl;
    }
}

void searchAppointment()
{
    int id;
    cout << "Enter Appointment ID: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < appointmentCount; ++i)
    {
        if (appointments[i].appointmentID == id)
        {
            cout << "Appointment ID: " << appointments[i].appointmentID << endl;
            cout << "Patient ID: " << appointments[i].patientID << endl;
            cout << "Doctor ID: " << appointments[i].doctorID << endl;
            cout << "Date: " << appointments[i].date << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Appointment not found!" << endl;
    }
}
void updatePatient()
{
    int id;
    cout << "Enter Patient ID: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < patientCount; ++i)
    {
        if (patients[i].id == id)
        {
            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, patients[i].name);
            cout << "Enter New Age: ";
            cin >> patients[i].age;
            cout << "Enter New Ailment: ";
            cin.ignore();
            getline(cin, patients[i].ailment);
            cout << "Patient record updated successfully!" << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Patient not found!" << endl;
    }
}

void updateDoctor()
{
    int id;
    cout << "Enter Doctor ID: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < doctorCount; ++i)
    {
        if (doctors[i].id == id)
        {
            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, doctors[i].name);
            cout << "Enter New Age: ";
            cin >> doctors[i].age;
            cout << "Enter New Specialization: ";
            cin.ignore();
            getline(cin, doctors[i].specialization);
            cout << "Doctor record updated successfully!" << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Doctor not found!" << endl;
    }
}

void updateBilling()
{
    int id;
    cout << "Enter Patient ID: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < billCount; ++i)
    {
        if (bills[i].patientID == id)
        {
            cout << "Enter New Patient Name: ";
            cin.ignore();
            getline(cin, bills[i].patientName);
            cout << "Enter New Patient Age: ";
            cin >> bills[i].patientAge;
            cout << "Enter New Doctor Name: ";
            cin.ignore();
            getline(cin, bills[i].doctorName);
            cout << "Enter New Doctor ID: ";
            cin >> bills[i].doctorID;
            cout << "Enter New Amount: ";
            cin >> bills[i].amount;
            cout << "Bill record updated successfully!" << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Bill not found!" << endl;
    }
}

void updateAppointment()
{
    int id;
    cout << "Enter Appointment ID: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < appointmentCount; ++i)
    {
        if (appointments[i].appointmentID == id)
        {
            cout << "Enter New Patient ID: ";
            cin >> appointments[i].patientID;
            cout << "Enter New Doctor ID: ";
            cin >> appointments[i].doctorID;
            cout << "Enter New Date (YYYY-MM-DD): ";
            cin.ignore();
            getline(cin, appointments[i].date);
            cout << "Appointment record updated successfully!" << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Appointment not found!" << endl;
    }
}

void deletePatient()
{
    int id;
    cout << "Enter Patient ID: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < patientCount; ++i)
    {
        if (patients[i].id == id)
        {
            for (int j = i; j < patientCount - 1; ++j)
            {
                patients[j] = patients[j + 1];
            }
            patientCount--;
            cout << "Patient record deleted successfully!" << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Patient not found!" << endl;
    }
}

void deleteDoctor()
{
    int id;
    cout << "Enter Doctor ID: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < doctorCount; ++i)
    {
        if (doctors[i].id == id)
        {
            for (int j = i; j < doctorCount - 1; ++j)
            {
                doctors[j] = doctors[j + 1];
            }
            doctorCount--;
            cout << "Doctor record deleted successfully!" << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Doctor not found!" << endl;
    }
}

void deleteAppointment()
{
    int id;
    cout << "Enter Appointment ID: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < appointmentCount; ++i)
    {
        if (appointments[i].appointmentID == id)
        {
            for (int j = i; j < appointmentCount - 1; ++j)
            {
                appointments[j] = appointments[j + 1];
            }
            appointmentCount--;
            cout << "Appointment record deleted successfully!" << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Appointment not found!" << endl;
    }
}

void deleteBill()
{
    int id;
    cout << "Enter Patient ID: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < billCount; ++i)
    {
        if (bills[i].patientID == id)
        {
            for (int j = i; j < billCount - 1; ++j)
            {
                bills[j] = bills[j + 1];
            }
            billCount--;
            cout << "Bill record deleted successfully!" << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Bill not found!" << endl;
    }
}

void adminMenu()
{
    int choice;
    while (true)
    {
        cout << "Hospital Management System" << endl;
        cout<<"----------------------------"<<endl;
        cout << "1. | Add Patient           |"<< endl;
        cout << "2. | Add Doctor            |"<< endl;
        cout << "3. | Add Bill              |" << endl;
        cout << "4. | Add Appointment       |" << endl;
        cout << "5. | Display Patients      |" << endl;
        cout << "6. | Display Doctors       |" << endl;
        cout << "7. | Display Bills         |" << endl;
        cout << "8. | Display Appointments  |" << endl;
        cout << "9. | Search Patient        |" << endl;
        cout << "10.| Search Doctor         |" << endl;
        cout << "11.| Search Bill           |" << endl;
        cout << "12.| Search Appointment    |" << endl;
        cout << "13.| Update Patient        |" << endl;
        cout << "14.| Update Doctor         |" << endl;
        cout << "15.| Update Bill           |" << endl;
        cout << "16.| Update Appointment    |" << endl;
        cout << "17.| Delete Patient        |" << endl;
        cout << "18.| Delete Doctor         |" << endl;
        cout << "19.| Delete Bill           |" << endl;
        cout << "20.| Delete Appointment    |" << endl;
        cout << "21.| Exit                  |" << endl;
        cout<<"----------------------------"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addPatient();
            break;
        case 2:
            addDoctor();
            break;
        case 3:
            addBilling();
            break;
        case 4:
            addAppointment();
            break;
        case 5:
            displayPatients();
            break;
        case 6:
            displayDoctors();
            break;
        case 7:
            displayBills();
            break;
        case 8:
            displayAppointments();
            break;
        case 9:
            searchPatient();
            break;
        case 10:
            searchDoctor();
            break;
        case 11:
            searchBill();
            break;
        case 12:
            searchAppointment();
            break;
        case 13:
            updatePatient();
            break;
        case 14:
            updateDoctor();
            break;
        case 15:
            updateBilling();
            break;
        case 16:
            updateAppointment();
            break;
        case 17:
            deletePatient();
            break;
        case 18:
            deleteDoctor();
            break;
        case 19:
            deleteBill();
            break;
        case 20:
            deleteAppointment();
            break;
        case 21:
            return;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    }
}

int main()
{
    string correct_password = "Tabussam"; 
    if (!authenticate(correct_password))
    {
        cout << "Access denied." << endl;
        return 0;
    }

    adminMenu();
     
    return 0;
}
