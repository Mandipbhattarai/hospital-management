#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <sstream>
#include <iomanip>

using namespace std;
/*
 ----------------------------------------------------------------------------------------------------------------------------------------------
 ----------------------------------------------------------------------------------------------------------------------------------------------
 -------------------------------------------------------------  STARTING OF PATIENT CLASS -----------------------------------------------------
 ----------------------------------------------------------------------------------------------------------------------------------------------
 ----------------------------------------------------------------------------------------------------------------------------------------------
 */
class Patient
{
public:
    int id;
    string name;
    string admissionDate;
    int age;
    string gender;
    string diagnosis;
    string ward;

    Patient(int id, const string &name, const string &admissionDate, int age, const string &gender, const string &diagnosis, const string &ward)
    {
        this->id = id;
        this->name = name;
        this->admissionDate = admissionDate;
        this->age = age;
        this->gender = gender;
        this->diagnosis = diagnosis;
        this->ward = ward;
    }

    // Method to print patient details
    void displayPatient() const
    {
        cout << "Patient ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Admission Date: " << admissionDate << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Diagnosis: " << diagnosis << endl;
        cout << "Ward: " << ward << endl;
    }
};
/*
 ----------------------------------------------------------------------------------------------------------------------------------------------
 ----------------------------------------------------------------------------------------------------------------------------------------------
 -------------------------------------------------------------  STARTING OF DOCTOR CLASS ------------------------------------------------------
 ----------------------------------------------------------------------------------------------------------------------------------------------
 ----------------------------------------------------------------------------------------------------------------------------------------------
 */
class Doctor
{
public:
    int id;
    string name;
    string specialization;
    int experienceYears;
    string qualification;
    string schedule;

    Doctor(int id, const string &name, const string &specialization, int experienceYears, const string &qualification, const string &schedule)
    {
        this->id = id;
        this->name = name;
        this->specialization = specialization;
        this->experienceYears = experienceYears;
        this->qualification = qualification;
        this->schedule = schedule;
    }

    // Method to print doctor details
    void displayDoctor() const
    {
        cout << "Doctor ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Experience Years: " << experienceYears << endl;
        cout << "Qualification: " << qualification << endl;
        cout << "Schedule: " << schedule << endl;
    }
};
/*
 ----------------------------------------------------------------------------------------------------------------------------------------------
 ----------------------------------------------------------------------------------------------------------------------------------------------
 -------------------------------------------------------------  STARTING OF STAFF CLASS -------------------------------------------------------
 ----------------------------------------------------------------------------------------------------------------------------------------------
 ----------------------------------------------------------------------------------------------------------------------------------------------
 */
class Staff
{
public:
    int id;
    string name;
    string department;
    int yearsOfService;
    string position;
    string shift;

    Staff(int id, const string &name, const string &department, int yearsOfService, const string &position, const string &shift)
    {
        this->id = id;
        this->name = name;
        this->department = department;
        this->yearsOfService = yearsOfService;
        this->position = position;
        this->shift = shift;
    }

    // Method to print staff details
    void displayStaff() const
    {
        cout << "Staff ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Years of Service: " << yearsOfService << endl;
        cout << "Position: " << position << endl;
        cout << "Shift: " << shift << endl;
    }
};

/*
 ----------------------------------------------------------------------------------------------------------------------------------------------
 ----------------------------------------------------------------------------------------------------------------------------------------------
 -------------------------------------------------------------  STARTING OF HOSPITAL CLASS ----------------------------------------------------
 ----------------------------------------------------------------------------------------------------------------------------------------------
 ----------------------------------------------------------------------------------------------------------------------------------------------
 */
class HospitalManagementSystem
{
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Staff> staff;

public:
    /*
     ---------------------------------------------------------------------------------------------------------------------------------------------
     ---------------------------------------------------------------------------------------------------------------------------------------------
     ------------------------------------------------------------- ADDING RECORDS FUNCTIONALITY --------------------------------------------------
     ---------------------------------------------------------------------------------------------------------------------------------------------
     ---------------------------------------------------------------------------------------------------------------------------------------------
     */

    // Function to validate the admission date format
    bool isValidAdmissionDate(const string &date)
    {
        // Check if the date has the format "YYYY-MM-DD"
        if (date.size() != 10)
            return false;

        for (int i = 0; i < 10; i++)
        {
            if (i == 4 || i == 7)
            {
                if (date[i] != '-')
                    return false;
            }
            else
            {
                if (!isdigit(date[i]))
                    return false;
            }
        }

        return true;
    }

    // Method to input patient information
    void addNewPatient()
    {
        int id, age;
        string name, admissionDate, gender, diagnosis, ward;

        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter Patient ID: ";
        cin >> id;

        for (const Patient &patient : patients)
        {
            if (patient.id == id)
            {
                cout << "Patient with the same ID already exists. Please choose a unique ID." << endl;
                return;
            }
        }

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Admission Date [YYYY-MM-DD]: ";
        getline(cin, admissionDate);

        if (!isValidAdmissionDate(admissionDate))
        {
            cout << "Invalid admission date format. Please use YYYY-MM-DD format." << endl;
            return;
        }

        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender: ";
        cin.ignore();
        getline(cin, gender);
        cout << "Enter Diagnosis: ";
        getline(cin, diagnosis);
        cout << "Enter Ward: ";
        getline(cin, ward);

        Patient newPatient(id, name, admissionDate, age, gender, diagnosis, ward);
        patients.push_back(newPatient);
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Patient record added successfully." << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    }

    // Method to input doctor information
    void addNewDoctor()
    {
        int id, experienceYears;
        string name, specialization, qualification, schedule;

        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter Doctor ID: ";
        cin >> id;

        for (const Doctor &doctor : doctors)
        {
            if (doctor.id == id)
            {
                cout << "Doctor with the same ID already exists. Please choose a unique ID." << endl;
                return;
            }
        }

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Specialization: ";
        getline(cin, specialization);
        cout << "Enter Qualification: ";
        getline(cin, qualification);
        cout << "Enter Experience Years: ";
        cin >> experienceYears;
        cout << "Enter Schedule: ";
        cin.ignore();
        getline(cin, schedule);

        Doctor newDoctor(id, name, specialization, experienceYears, qualification, schedule);
        doctors.push_back(newDoctor);
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Doctor record added successfully." << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    }

    // Method to input staff information
    void addNewStaff()
    {
        int id, yearsOfService;
        string name, department, position, shift;

        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter Staff ID: ";
        cin >> id;

        for (const Staff &staffMember : staff)
        {
            if (staffMember.id == id)
            {
                cout << "Staff member with the same ID already exists. Please choose a unique ID." << endl;
                return;
            }
        }

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Department: ";
        getline(cin, department);
        cout << "Enter Position: ";
        getline(cin, position);
        cout << "Enter Years of Service: ";
        cin >> yearsOfService;
        cout << "Enter Shift: ";
        cin.ignore();
        getline(cin, shift);

        Staff newStaff(id, name, department, yearsOfService, position, shift);
        staff.push_back(newStaff);
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Staff record added successfully." << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    }

    /*
     ---------------------------------------------------------------------------------------------------------------------------------------------
     ---------------------------------------------------------------------------------------------------------------------------------------------
     -------------------------------------------------------------  SEARCHING RECORDS FUNCTIONALITY ----------------------------------------------
     ---------------------------------------------------------------------------------------------------------------------------------------------
     ---------------------------------------------------------------------------------------------------------------------------------------------
     */

    // Method to search for a record
    void searchRecords()
    {
        int choice;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "1. Search for a Patient" << endl;
        cout << "2. Search for a Doctor" << endl;
        cout << "3. Search for a Staff" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            searchPatients();
            break;
        }
        case 2:
        {
            searchDoctors();
            break;
        }
        case 3:
        {
            searchStaff();
            break;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }

    // Method to search for a patient by a specific attribute (ID and Name only)
    void searchPatients()
    {
        int choice;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Search Patient by:" << endl;
        cout << "1. ID" << endl;
        cout << "2. Name" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        string searchValue;
        cout << "Enter the value to search for: ";
        cin.ignore();
        getline(cin, searchValue);
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

        switch (choice)
        {
        case 1:
        {
            for (const Patient &patient : patients)
            {
                if (to_string(patient.id) == searchValue)
                {
                    cout << "Patient Found:-" << endl;
                    patient.displayPatient();
                }
                else
                {
                    cout << "Patient Not Found" << endl;
                }
            }
            break;
        }
        case 2:
        {
            for (const Patient &patient : patients)
            {
                if (patient.name == searchValue)
                {
                    cout << "Patient Found:-" << endl;
                    patient.displayPatient();
                }
                else
                {
                    cout << "Patient Not Found" << endl;
                }
            }
            break;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }

    // Method to search for a doctor by a specific attribute (ID and Name only)
    void searchDoctors()
    {
        int choice;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Search Doctor by:" << endl;
        cout << "1. ID" << endl;
        cout << "2. Name" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        string searchValue;
        cout << "Enter the value to search for: ";
        cin.ignore();
        getline(cin, searchValue);
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

        switch (choice)
        {
        case 1:
        {
            for (const Doctor &doctor : doctors)
            {
                if (to_string(doctor.id) == searchValue)
                {
                    cout << "Doctor Found:-" << endl;
                    doctor.displayDoctor();
                }
                else
                {
                    cout << "Doctor Not Found" << endl;
                }
            }
            break;
        }
        case 2:
        {
            for (const Doctor &doctor : doctors)
            {
                if (doctor.name == searchValue)
                {
                    cout << "Doctor Found:-" << endl;
                    doctor.displayDoctor();
                }
                else
                {
                    cout << "Doctor Not Found" << endl;
                }
            }
            break;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }

    // Method to search for staff by a specific attribute (ID and Name only)
    void searchStaff()
    {
        int choice;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Search Staff by:" << endl;
        cout << "1. ID" << endl;
        cout << "2. Name" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        string searchValue;
        cout << "Enter the value to search for: ";
        cin.ignore();
        getline(cin, searchValue);
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

        switch (choice)
        {
        case 1:
        {
            for (const Staff &staff : staff)
            {
                if (to_string(staff.id) == searchValue)
                {
                    cout << "Staff Found:-" << endl;
                    staff.displayStaff();
                }
                else
                {
                    cout << "Staff Not Found" << endl;
                }
            }
            break;
        }
        case 2:
        {
            for (const Staff &staff : staff)
            {
                if (staff.name == searchValue)
                {
                    cout << "Staff Found:-" << endl;
                    staff.displayStaff();
                }
                else
                {
                    cout << "Staff Not Found" << endl;
                }
            }
            break;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }

    /*
     ---------------------------------------------------------------------------------------------------------------------------------------------
     ---------------------------------------------------------------------------------------------------------------------------------------------
     --------------------------------------------------------------  UPDATING RECORDS FUNCTIONALITY ----------------------------------------------
     ---------------------------------------------------------------------------------------------------------------------------------------------
     ---------------------------------------------------------------------------------------------------------------------------------------------
     */

    // Method to update a record
    void updateRecord()
    {
        int choice;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Whose record do you want to update?" << endl;
        cout << "1. Patient" << endl;
        cout << "2. Doctor" << endl;
        cout << "3. Staff" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

        switch (choice)
        {
        case 1:
            updatePatientRecord();
            break;
        case 2:
            updateDoctorRecord();
            break;
        case 3:
            updateStaffRecord();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    // Method to update a patient's record
    void updatePatientRecord()
    {
        int id;
        cout << "Enter the ID of the patient to update: ";
        cin >> id;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

        for (Patient &patient : patients)
        {
            if (patient.id == id)
            {
                cout << "Updating patient with ID: " << id << endl;

                cout << "What would you like to update?" << endl;
                cout << "1. Name" << endl;
                cout << "2. Admission Date" << endl;
                cout << "3. Age" << endl;
                cout << "4. Gender" << endl;
                cout << "5. Diagnosis" << endl;
                cout << "6. Ward" << endl;
                cout << "7. Update All Attributes" << endl;

                int updateChoice;
                cout << "Enter your choice: ";
                cin >> updateChoice;
                cin.ignore();
                cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

                if (updateChoice == 7)
                {
                    cout << "Enter the new name: ";
                    getline(cin, patient.name);

                    cout << "Enter the new admission date: ";
                    getline(cin, patient.admissionDate);

                    cout << "Enter the new age: ";
                    cin >> patient.age;

                    cout << "Enter the new gender: ";
                    cin.ignore();
                    getline(cin, patient.gender);

                    cout << "Enter the new diagnosis: ";
                    getline(cin, patient.diagnosis);

                    cout << "Enter the new ward: ";
                    getline(cin, patient.ward);
                }
                else if (updateChoice >= 1 && updateChoice <= 6)
                {
                    string newValue;
                    switch (updateChoice)
                    {
                    case 1:
                        cout << "Enter the new name: ";
                        getline(cin, newValue);
                        patient.name = newValue;
                        break;
                    case 2:
                        cout << "Enter the new admission date: ";
                        getline(cin, newValue);
                        patient.admissionDate = newValue;
                        break;
                    case 3:
                        cout << "Enter the new age: ";
                        cin >> patient.age;
                        break;
                    case 4:
                        cout << "Enter the new gender: ";
                        cin.ignore();
                        getline(cin, newValue);
                        patient.gender = newValue;
                        break;
                    case 5:
                        cout << "Enter the new diagnosis: ";
                        getline(cin, newValue);
                        patient.diagnosis = newValue;
                        break;
                    case 6:
                        cout << "Enter the new ward: ";
                        getline(cin, newValue);
                        patient.ward = newValue;
                        break;
                    }
                }
                else
                {
                    cout << "Invalid choice. No updates were made." << endl;
                }

                cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
                cout << "Patient record updated successfully!" << endl;
                return;
            }
        }

        cout << "Patient with ID " << id << " not found." << endl;
    }

    // Method to update a doctor's record
    void updateDoctorRecord()
    {
        int id;
        cout << "Enter the ID of the doctor to update: ";
        cin >> id;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

        for (Doctor &doctor : doctors)
        {
            if (doctor.id == id)
            {
                cout << "Updating doctor with ID: " << id << endl;

                cout << "What would you like to update?" << endl;
                cout << "1. Name" << endl;
                cout << "2. Specialization" << endl;
                cout << "3. Experience Years" << endl;
                cout << "4. Qualification" << endl;
                cout << "5. Schedule" << endl;
                cout << "6. Update All Attributes" << endl;

                int updateChoice;
                cout << "Enter your choice: ";
                cin >> updateChoice;
                cin.ignore();
                cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

                if (updateChoice == 6)
                {
                    cout << "Enter the new name: ";
                    getline(cin, doctor.name);

                    cout << "Enter the new specialization: ";
                    getline(cin, doctor.specialization);

                    cout << "Enter the new experience years: ";
                    cin >> doctor.experienceYears;

                    cout << "Enter the new qualification: ";
                    cin.ignore();
                    getline(cin, doctor.qualification);

                    cout << "Enter the new schedule: ";
                    getline(cin, doctor.schedule);
                }
                else if (updateChoice >= 1 && updateChoice <= 5)
                {
                    string newValue;
                    switch (updateChoice)
                    {
                    case 1:
                        cout << "Enter the new name: ";
                        getline(cin, newValue);
                        doctor.name = newValue;
                        break;
                    case 2:
                        cout << "Enter the new specialization: ";
                        getline(cin, newValue);
                        doctor.specialization = newValue;
                        break;
                    case 3:
                        cout << "Enter the new experience years: ";
                        cin >> doctor.experienceYears;
                        break;
                    case 4:
                        cout << "Enter the new qualification: ";
                        cin.ignore();
                        getline(cin, newValue);
                        doctor.qualification = newValue;
                        break;
                    case 5:
                        cout << "Enter the new schedule: ";
                        getline(cin, newValue);
                        doctor.schedule = newValue;
                        break;
                    }
                }
                else
                {
                    cout << "Invalid choice. No updates were made." << endl;
                }

                cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
                cout << "Doctor's record updated successfully!" << endl;
                return;
            }
        }

        cout << "Doctor with ID " << id << " not found." << endl;
    }

    // Method to update a staff member's record
    void updateStaffRecord()
    {
        int id;
        cout << "Enter the ID of the staff member to update: ";
        cin >> id;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

        for (Staff &staffMember : staff)
        {
            if (staffMember.id == id)
            {
                cout << "Updating staff member with ID: " << id << endl;

                cout << "What would you like to update?" << endl;
                cout << "1. Name" << endl;
                cout << "2. Department" << endl;
                cout << "3. Years of Service" << endl;
                cout << "4. Position" << endl;
                cout << "5. Shift" << endl;
                cout << "6. Update All Attributes" << endl;

                int updateChoice;
                cout << "Enter your choice: ";
                cin >> updateChoice;
                cin.ignore();
                cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

                if (updateChoice == 6)
                {
                    cout << "Enter the new name: ";
                    getline(cin, staffMember.name);

                    cout << "Enter the new department: ";
                    getline(cin, staffMember.department);

                    cout << "Enter the new years of service: ";
                    cin >> staffMember.yearsOfService;

                    cout << "Enter the new position: ";
                    cin.ignore();
                    getline(cin, staffMember.position);

                    cout << "Enter the new shift: ";
                    getline(cin, staffMember.shift);
                }
                else if (updateChoice >= 1 && updateChoice <= 5)
                {
                    string newValue;
                    switch (updateChoice)
                    {
                    case 1:
                        cout << "Enter the new name: ";
                        getline(cin, newValue);
                        staffMember.name = newValue;
                        break;
                    case 2:
                        cout << "Enter the new department: ";
                        getline(cin, newValue);
                        staffMember.department = newValue;
                        break;
                    case 3:
                        cout << "Enter the new years of service: ";
                        cin >> staffMember.yearsOfService;
                        break;
                    case 4:
                        cout << "Enter the new position: ";
                        cin.ignore();
                        getline(cin, newValue);
                        staffMember.position = newValue;
                        break;
                    case 5:
                        cout << "Enter the new shift: ";
                        getline(cin, newValue);
                        staffMember.shift = newValue;
                        break;
                    }
                }
                else
                {
                    cout << "Invalid choice. No updates were made." << endl;
                }

                cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
                cout << "Staff member's record updated successfully!" << endl;
                return;
            }
        }

        cout << "Staff member with ID " << id << " not found." << endl;
    }

    /*
    ----------------------------------------------------------------------------------------------------------------------------------------------
    ----------------------------------------------------------------------------------------------------------------------------------------------
    ------------------------------------------------------------------ DISPLAY RECORDS FUNCTIONALITY ---------------------------------------------
    ----------------------------------------------------------------------------------------------------------------------------------------------
    ----------------------------------------------------------------------------------------------------------------------------------------------
    */

    // Method to display records
    void displayRecords()
    {
        int choice;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Whose records do you want to display?" << endl;
        cout << "1. Display Patient by ID" << endl;
        cout << "2. Display Patient by Name" << endl;
        cout << "3. Display Doctor by ID" << endl;
        cout << "4. Display Doctor by Name" << endl;
        cout << "5. Display Staff by ID" << endl;
        cout << "6. Display Staff by Name" << endl;
        cout << "7. Display All Patient Records" << endl;
        cout << "8. Display All Doctor Records" << endl;
        cout << "9. Display All Staff Records" << endl;
        cout << "10. Display All Records (Patients, Doctors, and Staff)" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

        switch (choice)
        {
        case 1:
            displayPatientByID();
            break;
        case 2:
            displayPatientByName();
            break;
        case 3:
            displayDoctorByID();
            break;
        case 4:
            displayDoctorByName();
            break;
        case 5:
            displayStaffByID();
            break;
        case 6:
            displayStaffByName();
            break;
        case 7:
            displayAllPatients();
            break;
        case 8:
            displayAllDoctors();
            break;
        case 9:
            displayAllStaff();
            break;
        case 10:
            displayAllRecords();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    void displayPatientByID()
    {
        int patientID;
        cout << "Enter the ID of the patient to display: ";
        cin >> patientID;

        for (const Patient &patient : patients)
        {
            if (patient.id == patientID)
            {
                patient.displayPatient();
                return;
            }
        }
        cout << "Patient with ID " << patientID << " not found." << endl;
    }

    void displayPatientByName()
    {
        string patientName;
        cout << "Enter the name of the patient to display: ";
        cin.ignore();
        getline(cin, patientName);

        for (const Patient &patient : patients)
        {
            if (patient.name == patientName)
            {
                patient.displayPatient();
                return;
            }
        }
        cout << "Patient with name " << patientName << " not found." << endl;
    }

    void displayDoctorByID()
    {
        int doctorID;
        cout << "Enter the ID of the doctor to display: ";
        cin >> doctorID;

        for (const Doctor &doctor : doctors)
        {
            if (doctor.id == doctorID)
            {
                doctor.displayDoctor();
                return;
            }
        }
        cout << "Doctor with ID " << doctorID << " not found." << endl;
    }

    void displayDoctorByName()
    {
        string doctorName;
        cout << "Enter the name of the doctor to display: ";
        cin.ignore();
        getline(cin, doctorName);

        for (const Doctor &doctor : doctors)
        {
            if (doctor.name == doctorName)
            {
                doctor.displayDoctor();
                return;
            }
        }
        cout << "Doctor with name " << doctorName << " not found." << endl;
    }

    void displayStaffByID()
    {
        int staffID;
        cout << "Enter the ID of the staff to display: ";
        cin >> staffID;

        for (const Staff &staff : staff)
        {
            if (staff.id == staffID)
            {
                staff.displayStaff();
                return;
            }
        }
        cout << "Staff with ID " << staffID << " not found." << endl;
    }

    void displayStaffByName()
    {
        string staffName;
        cout << "Enter the name of the staff to display: ";
        cin.ignore();
        getline(cin, staffName);

        for (const Staff &staff : staff)
        {
            if (staff.name == staffName)
            {
                staff.displayStaff();
                return;
            }
        }
        cout << "Staff with name " << staffName << " not found." << endl;
    }

    void displayAllPatients()
    {
        cout << "All Patient Records:" << endl;
        for (const Patient &patient : patients)
        {
            patient.displayPatient();
            cout << "--------------------------------------------------" << endl;
        }
    }

    void displayAllDoctors()
    {
        cout << "All Doctor Records:" << endl;
        for (const Doctor &doctor : doctors)
        {
            doctor.displayDoctor();
            cout << "--------------------------------------------------" << endl;
        }
    }

    void displayAllStaff()
    {
        cout << "All Staff Records:" << endl;
        for (const Staff &staff : staff)
        {
            staff.displayStaff();
            cout << "--------------------------------------------------" << endl;
        }
    }

    void displayAllRecords()
    {
        cout << "All Records (Patients, Doctors, and Staff):" << endl;
        cout << "====================== Patients: =======================" << endl;
        for (const Patient &patient : patients)
        {
            patient.displayPatient();
            cout << "-------------------------------------------" << endl;
        }

        cout << "====================== Doctors: ========================" << endl;
        for (const Doctor &doctor : doctors)
        {
            doctor.displayDoctor();
            cout << "-------------------------------------------" << endl;
        }

        cout << "======================= Staff: ========================" << endl;
        for (const Staff &staff : staff)
        {
            staff.displayStaff();
            cout << "-------------------------------------------" << endl;
        }
    }

    /*
    ----------------------------------------------------------------------------------------------------------------------------------------------
    ----------------------------------------------------------------------------------------------------------------------------------------------
    ------------------------------------------------------------------ DELETE RECORDS FUNCTIONALITY ---------------------------------------------
    ----------------------------------------------------------------------------------------------------------------------------------------------
    ----------------------------------------------------------------------------------------------------------------------------------------------
    */

    void deleteRecords()
    {
        int choice;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Whose record do you want to delete?" << endl;
        cout << "1. Patient" << endl;
        cout << "2. Doctor" << endl;
        cout << "3. Staff" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

        switch (choice)
        {
        case 1:
            deletePatientRecord();
            break;
        case 2:
            deleteDoctorRecord();
            break;
        case 3:
            deleteStaffRecord();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    void deletePatientRecord()
    {
        int patientID;
        cout << "Enter the ID of the patient to delete: ";
        cin >> patientID;

        for (auto it = patients.begin(); it != patients.end();)
        {
            if (it->id == patientID)
            {
                it = patients.erase(it);
                cout << "Patient with ID " << patientID << " has been deleted." << endl;
                return;
            }
            else
            {
                ++it;
            }
        }
        cout << "Patient with ID " << patientID << " not found." << endl;
    }

    void deleteDoctorRecord()
    {
        int doctorID;
        cout << "Enter the ID of the doctor to delete: ";
        cin >> doctorID;

        for (auto it = doctors.begin(); it != doctors.end();)
        {
            if (it->id == doctorID)
            {
                it = doctors.erase(it);
                cout << "Doctor with ID " << doctorID << " has been deleted." << endl;
                return;
            }
            else
            {
                ++it;
            }
        }
        cout << "Doctor with ID " << doctorID << " not found." << endl;
    }

    void deleteStaffRecord()
    {
        int staffID;
        cout << "Enter the ID of the staff to delete: ";
        cin >> staffID;

        for (auto it = staff.begin(); it != staff.end();)
        {
            if (it->id == staffID)
            {
                it = staff.erase(it);
                cout << "Staff with ID " << staffID << " has been deleted." << endl;
                return;
            }
            else
            {
                ++it;
            }
        }
        cout << "Staff with ID " << staffID << " not found." << endl;
    }

    /*
    ----------------------------------------------------------------------------------------------------------------------------------------------
    ----------------------------------------------------------------------------------------------------------------------------------------------
    -------------------------------------------------------------- DELETE ALL RECORDS FUNCTIONALITY ---------------------------------------------
    ----------------------------------------------------------------------------------------------------------------------------------------------
    ----------------------------------------------------------------------------------------------------------------------------------------------
    */

    void deleteALLRecords()
    {
        int choice;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "What records do you want to delete?" << endl;
        cout << "1. Delete all Patient Records" << endl;
        cout << "2. Delete all Doctor Records" << endl;
        cout << "3. Delete all Staff Records" << endl;
        cout << "4. Delete all Records (Patients, Doctors, and Staff)" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

        switch (choice)
        {
        case 1:
            deleteAllPatients();
            break;
        case 2:
            deleteAllDoctors();
            break;
        case 3:
            deleteAllStaff();
            break;
        case 4:
            deleteAllRecordsFromDatabase();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    void deleteAllPatients()
    {
        patients.clear();
        cout << "All Patient Records have been deleted." << endl;
    }

    void deleteAllDoctors()
    {
        doctors.clear();
        cout << "All Doctor Records have been deleted." << endl;
    }

    void deleteAllStaff()
    {
        staff.clear();
        cout << "All Staff Records have been deleted." << endl;
    }

    void deleteAllRecordsFromDatabase()
    {
        patients.clear();
        doctors.clear();
        staff.clear();
        cout << "All Records (Patients, Doctors, and Staff) have been deleted." << endl;
    }

    /*
    ----------------------------------------------------------------------------------------------------------------------------------------------
    ----------------------------------------------------------------------------------------------------------------------------------------------
    --------------------------------------------------------------------- COUNTING RECORDS ------------------------------------------------------
    ----------------------------------------------------------------------------------------------------------------------------------------------
    ----------------------------------------------------------------------------------------------------------------------------------------------
    */

    void countRecords()
    {
        int totalPatients = patients.size();
        int totalDoctors = doctors.size();
        int totalStaff = staff.size();
        int totalRecords = totalPatients + totalDoctors + totalStaff;

        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Total Patients: " << totalPatients << endl;
        cout << "Total Doctors: " << totalDoctors << endl;
        cout << "Total Staff: " << totalStaff << endl;
        cout << "Total Records in the Database: " << totalRecords << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    }

    /*
    ----------------------------------------------------------------------------------------------------------------------------------------------
    ----------------------------------------------------------------------------------------------------------------------------------------------
    --------------------------------------------------------------------- SORTING RECORDS --------------------------------------------------------
    ----------------------------------------------------------------------------------------------------------------------------------------------
    ----------------------------------------------------------------------------------------------------------------------------------------------
    */

    void sortRecords()
    {
        int choice;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Sort Records:" << endl;
        cout << "1. Sort Patients by ID" << endl;
        cout << "2. Sort Patients by Admission Date" << endl;
        cout << "3. Sort Doctors by ID" << endl;
        cout << "4. Sort Doctors by Experience Years" << endl;
        cout << "5. Sort Staff by ID" << endl;
        cout << "6. Sort Staff by Years of Service" << endl;
        cout << "7. Sort All Records by ID" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

        switch (choice)
        {
        case 1:
            sortPatientsByID();
            break;
        case 2:
            sortPatientsByAdmissionDate();
            break;
        case 3:
            sortDoctorsByID();
            break;
        case 4:
            sortDoctorsByExperienceYears();
            break;
        case 5:
            sortStaffByID();
            break;
        case 6:
            sortStaffByYearsOfService();
            break;
        case 7:
            sortAllRecordsByID();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    void sortPatientsByID()
    {
        sort(patients.begin(), patients.end(), [](const Patient &a, const Patient &b)
             { return a.id < b.id; });
        cout << "Patients sorted by ID (ascending)." << endl;
    }

    void sortPatientsByAdmissionDate()
    {
        sort(patients.begin(), patients.end(), [this](const Patient &a, const Patient &b) -> bool
             {
        int admissionYears1 = AdmissionYears(a.admissionDate);
        int admissionYears2 = AdmissionYears(b.admissionDate);
        return admissionYears1 > admissionYears2; });
        cout << "Patients sorted by Admission Date." << endl;
    }

    // Function to convert admission date to numeric value (difference in years)
    int AdmissionYears(const std::string &admissionDate)
    {
        // Get today's date
        auto now = std::chrono::system_clock::now();
        time_t today = std::chrono::system_clock::to_time_t(now);
        std::tm ltm;

        // Convert admission date string to time
        std::tm admissionTime;
        std::istringstream ss(admissionDate);
        ss >> std::get_time(&admissionTime, "%Y-%m-%d");

        // Make sure the parsing was successful
        if (ss.fail())
        {
            // Handle parsing error
            return -1;
        }

        // Get the current time
        time_t currentTime = time(nullptr);

        // Calculate the difference in seconds
        std::tm *timeInfo = localtime(&currentTime);
        int yearsDiff = timeInfo->tm_year - admissionTime.tm_year;

        // Check if the admission date has passed this year
        if (timeInfo->tm_mon < admissionTime.tm_mon || (timeInfo->tm_mon == admissionTime.tm_mon && timeInfo->tm_mday < admissionTime.tm_mday))
        {
            yearsDiff--;
        }

        return yearsDiff;
    }

    void sortDoctorsByID()
    {
        sort(doctors.begin(), doctors.end(), [](const Doctor &a, const Doctor &b)
             { return a.id < b.id; });
        cout << "Doctors sorted by ID (ascending)." << endl;
    }

    void sortDoctorsByExperienceYears()
    {
        sort(doctors.begin(), doctors.end(), [](const Doctor &a, const Doctor &b)
             { return a.experienceYears > b.experienceYears; });
        cout << "Doctors sorted by Experience Years (descending)." << endl;
    }

    void sortStaffByID()
    {
        sort(staff.begin(), staff.end(), [](const Staff &a, const Staff &b)
             { return a.id < b.id; });
        cout << "Staff sorted by ID (ascending)." << endl;
    }

    void sortStaffByYearsOfService()
    {
        sort(staff.begin(), staff.end(), [](const Staff &a, const Staff &b)
             { return a.yearsOfService > b.yearsOfService; });
        cout << "Staff sorted by Years of Service (descending)." << endl;
    }

    void sortAllRecordsByID()
    {
        sortPatientsByID();
        sortDoctorsByID();
        sortStaffByID();
        cout << "All Records sorted by ID (ascending)." << endl;
    }

    /*
    ----------------------------------------------------------------------------------------------------------------------------------------------
    ----------------------------------------------------------------------------------------------------------------------------------------------
    ------------------------------------------------------------------- GENERATE REPORT --------------------------------------------------------
    ----------------------------------------------------------------------------------------------------------------------------------------------
    ----------------------------------------------------------------------------------------------------------------------------------------------
    */

    void generateReportsMenu()
    {
        generateSummaryReport();
        generatePatientReport();
        generateDoctorReport();
        generateStaffReport();
    }
    void generatePatientReport()
    {
        cout << "=== Patient Report ===" << endl;
        for (const Patient &patient : patients)
        {
            patient.displayPatient();
            cout << "----------------------" << endl;
        }
    }
    void generateDoctorReport()
    {
        cout << "=== Doctor Report ===" << endl;
        for (const Doctor &doctor : doctors)
        {
            doctor.displayDoctor();
            cout << "----------------------" << endl;
        }
    }
    void generateStaffReport()
    {
        cout << "=== Staff Report ===" << endl;
        for (const Staff &staffMember : staff)
        {
            staffMember.displayStaff();
            cout << "----------------------" << endl;
        }
    }
    void generateSummaryReport()
    {
        cout << "=== Summary Report ===" << endl;
        cout << "Total Patients: " << patients.size() << endl;
        cout << "Total Doctors: " << doctors.size() << endl;
        cout << "Total Staff: " << staff.size() << endl;
        cout << "----------------------" << endl;
    }

    /*
    ----------------------------------------------------------------------------------------------------------------------------------------------
    ----------------------------------------------------------------------------------------------------------------------------------------------
    ------------------------------------------------------------------ PROJECT RUNNING FUNCTIONALITY ---------------------------------------------
    ----------------------------------------------------------------------------------------------------------------------------------------------
    ----------------------------------------------------------------------------------------------------------------------------------------------
    */

    void displayMenu()
    {
        cout << "==================================  !!! Hospital Management System Menu !!!  ====================================" << endl;
        cout << "1. Add New Patient" << endl;
        cout << "2. Add New Doctor" << endl;
        cout << "3. Add New Staff" << endl;
        cout << "4. Search Records" << endl;
        cout << "5. Update Records" << endl;
        cout << "6. Display Records" << endl;
        cout << "7. Delete Records" << endl;
        cout << "8. Delete All Records" << endl;
        cout << "9. Count Records" << endl;
        cout << "10. Sort Records" << endl;
        cout << "11. Generate Reports" << endl;
        cout << "12. Exit" << endl;
    }

    void runProject()
    {
        int choice;
        do
        {
            displayMenu();
            cout << "=======================" << endl;
            cout << "ENTER YOUR CHOICE:= ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                addNewPatient();
                break;
            }
            case 2:
            {
                addNewDoctor();
                break;
            }
            case 3:
            {
                addNewStaff();
                break;
            }
            case 4:
            {
                searchRecords();
                break;
            }
            case 5:
            {
                updateRecord();
                break;
            }
            case 6:
            {
                displayRecords();
                break;
            }
            case 7:
            {
                deleteRecords();
                break;
            }
            case 8:
            {
                deleteALLRecords();
                break;
            }
            case 9:
            {
                countRecords();
                break;
            }
            case 10:
            {
                sortRecords();
                break;
            }
            case 11:
            {
                generateReportsMenu();
                break;
            }
            case 12:
            {
                cout << "Exiting the program." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        } while (choice != 12);
    }
};
/*
 ----------------------------------------------------------------------------------------------------------------------------------------------
 ----------------------------------------------------------------------------------------------------------------------------------------------
 -------------------------------------------------------------  END OF HOSPITAL CLASS ---------------------------------------------------------
 ----------------------------------------------------------------------------------------------------------------------------------------------
 ----------------------------------------------------------------------------------------------------------------------------------------------
 */

int main()
{
    HospitalManagementSystem hospital;
    hospital.runProject();

    return 0;
}