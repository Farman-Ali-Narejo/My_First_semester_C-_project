#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

  //  STRUCTURES

struct Start {	
    string id;
    string name;
    int age;
    string disease;
    string doctor;
};

struct Emergency {
    string caseID, name, type, doctor;
    int age, priority;
};

struct Death {
    string id;
    string name;
    string date;
    string cause;
};

  // GLOBAL VARIABLES

Start patients[100];
int countPatients=0;

Emergency e[50];
int eCount=0;

Death deaths[100];
int deathCount=0;


  // BASIC UTILITIES

void pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}
 //  PATIENT MANAGEMENT
// function no 1
void addPatient() {
    if (countPatients >= 100) {
        cout << "Database full!\n";
        return;
    }

    cout << "\n--- ADD NEW PATIENT ---\n";
    cout << "Enter Patient ID: ";
    cin >> patients[countPatients].id;

    for (int i = 0; i < countPatients; i++) {
        if (patients[i].id == patients[countPatients].id) {
            cout << "Error! ID already exists.\n";
            return;
        }
    }

    cout << "Enter Age: ";
    cin >> patients[countPatients].age;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, patients[countPatients].name);

    cout << "Enter Disease: ";
    getline(cin, patients[countPatients].disease);

    string doctors[] = {"Dr.Sana", "Dr.Aasim", "Dr.Allah Rakhya"};
    patients[countPatients].doctor = doctors[countPatients % 3];

    countPatients++;
    cout << "Patient added successfully!\n";
}
// function no 2
void showPatients() {
    if (countPatients == 0) {
        cout << "No records found.\n";
        return;
    }

    cout << "\n--- PATIENT LIST ---\n\n";
    cout << left
         << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(6) << "Age"
         << setw(20) << "Disease"
         << setw(15) << "Doctor" << endl;
    cout << "-------------------------------------------------------------\n";

    for (int i = 0; i < countPatients; i++) {
        cout << setw(10) << patients[i].id
             << setw(20) << patients[i].name
             << setw(6) << patients[i].age
             << setw(20) << patients[i].disease
             << setw(15) << patients[i].doctor << endl;
    }
}
// function no 3
void searchPatient() {
    string ID;
    cout << "Enter Patient ID: ";
    cin >> ID;

    for (int i = 0; i < countPatients; i++) {
        if (patients[i].id == ID) {
            cout << "\n--- PATIENT FOUND ---\n";
            cout << "Name: " << patients[i].name << endl;
            cout << "Age: " << patients[i].age << endl;
            cout << "Disease: " << patients[i].disease << endl;
            cout << "Doctor: " << patients[i].doctor << endl;
            return;
        }
    }
    cout << "Patient not found.\n";
}
// function no 4
void updatePatient() {
    string ID;
    cout << "\nEnter Patient ID to update: ";
    cin >> ID;
    cin.ignore();

    for (int i = 0; i < countPatients; i++) {
        if (patients[i].id == ID) {
            cout << "Enter new Name: ";
            getline(cin, patients[i].name);

            cout << "Enter new Age: ";
            cin >> patients[i].age;
            cin.ignore();

            cout << "Enter new Disease: ";
            getline(cin, patients[i].disease);

            cout << "Patient record updated successfully!\n";
            return;
        }
    }
    cout << "Patient not found!\n";
}
// function no 5
void deletePatient() {
    string ID;
    cout << "Enter Patient ID: ";
    cin >> ID;

    for (int i = 0; i < countPatients; i++) {
        if (patients[i].id == ID) {
            for (int j = i; j < countPatients - 1; j++)
                patients[j] = patients[j + 1];
            countPatients--;
            cout << "Patient Deleted!\n";
            return;
        }
    }
    cout << "Patient not found!\n";
}

  // EMERGENCY SECTION
// function no 6
void addEmergency() {
    cout << "\n--- ADD EMERGENCY ---\n";
    if(eCount>50){
cout<<"No space available";
 return;}	

    cout << "Case ID: ";
    cin >> e[eCount].caseID;
    cin.ignore();

    cout << "Name: ";
    getline(cin, e[eCount].name);

    cout << "Age: ";
    cin >> e[eCount].age;
    cin.ignore();

    cout << "Type: ";
    getline(cin, e[eCount].type);

    cout << "Doctor: ";
    getline(cin, e[eCount].doctor);

    cout << "Priority (1-3): ";
    cin >> e[eCount].priority;
    cin.ignore();

    eCount++;
    cout << "Emergency Added!\n";
}

  // SHOW EMERGENCY CASES (ADDED)
// function no 7
void showEmergency() {
    if (eCount == 0) {
        cout << "\nNo emergency cases available.\n";
        return;
    }

    cout << "\n----------- EMERGENCY CASES -----------\n\n";

    cout << left
         << setw(10) << "Case ID"
         << setw(20) << "Name"
         << setw(6)  << "Age"
         << setw(15) << "Type"
         << setw(15) << "Doctor"
         << setw(8)  << "Priority" << endl;

    cout << "---------------------------------------------------------------\n";

    for (int i = 0; i < eCount; i++) {
        cout << setw(10) << e[i].caseID
             << setw(20) << e[i].name
             << setw(6)  << e[i].age
             << setw(15) << e[i].type
             << setw(15) << e[i].doctor
             << setw(8)  << e[i].priority << endl;
    }
}

 // DEATH RECORD MANAGEMENT
// function no 8
void addDeathRecord() {
    while (deathCount < 100) {
        char addDeath;
        cout << "\nDo you want to add a death record? (y/n): ";
        cin >> addDeath;
        cin.ignore();

        if (addDeath == 'y' || addDeath == 'Y') {
            cout << "Enter Patient ID: ";
            getline(cin, deaths[deathCount].id);

            cout << "Enter Name: ";
            getline(cin, deaths[deathCount].name);

            cout << "Enter Year of Death: ";
            getline(cin, deaths[deathCount].date);

            cout << "Enter Cause of Death: ";
            getline(cin, deaths[deathCount].cause);

            deathCount++;
            cout << "Death record added.\n";

            if (deathCount >= 100) {
                cout << "Death record database full!\n";
                break;
            }
        } else {
            break;
        }
    }
}
// function no 9
void searchDeathRecords() {
    if (deathCount == 0) {
        cout << "No death records available.\n";
        return;
    }

    string searchYear;
    cout << "\nEnter year to search death records: ";
    cin >> searchYear;

    bool found = false;
    cout << "\n--- Death Records for Year " << searchYear << " ---\n";

    for (int i = 0; i < deathCount; i++) {
        if (deaths[i].date == searchYear) {
            cout << "Name: " << deaths[i].name << endl;
            cout << "Cause: " << deaths[i].cause << endl;
            cout << "-----------------------\n";
            found = true;
        }
    }

    if (!found)
        cout << "No records found.\n";
}
// function no 10
void showDeathRecords() {
    if (deathCount == 0) {
        cout << "\nNo death records available.\n";
        return;
    }

    cout << "\n----------- ALL DEATH RECORDS -----------\n\n";

    cout << left
         << setw(12) << "ID"
         << setw(20) << "Name"
         << setw(12) << "Year"
         << setw(25) << "Cause of Death" << endl;

    cout << "---------------------------------------------------------------\n";

    for (int i = 0; i < deathCount; i++) {
        cout << setw(12) << deaths[i].id
             << setw(20) << deaths[i].name
             << setw(12) << deaths[i].date
             << setw(25) << deaths[i].cause << endl;
    }
}
 // save file
// function 11

void saveAllData() {
    ofstream file("database.txt", ios::app);

    file << "\nPATIENTS\n";
    for (int i = 0; i < countPatients; i++) {
        file << patients[i].id << "|"
             << patients[i].name << "|"
             << patients[i].age << "|"
             << patients[i].disease << "|"
             << patients[i].doctor << "\n";
    }

    file << "\nEMERGENCY\n";
    for (int i = 0; i < eCount; i++) {
        file << e[i].caseID << " "
             << e[i].name << " "
             << e[i].age << " "
             << e[i].type << " "
             << e[i].doctor << " "
             << e[i].priority << "\n";
    }

    file << "\nDEATH\n";
    for (int i = 0; i < deathCount; i++) {
        file << deaths[i].id << " "
             << deaths[i].name << " "
             << deaths[i].date << " "
             << deaths[i].cause << "\n";
    }

    file.close();
    cout << "\nAll data appended to database.txt\n";
}

void readdata() {
    ifstream file("database.txt");
    if (!file) {
        cout << "Error: database.txt not found!\n";
        return;
    }

    string line;

    cout << "\n=========== READING DATA FROM FILE ===========\n";

    // ---------- READ PATIENTS ----------
    cout << "\n--- PATIENT LIST FROM FILE ---\n";
    cout << left
         << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(6)  << "Age"
         << setw(20) << "Disease"
         << setw(15) << "Doctor" << endl;
    cout << "-------------------------------------------------------------\n";

    while (getline(file, line)) {
        if (line == "PATIENTS") {        // section found
            while (getline(file, line) && !line.empty()) {
                string id, name, age, disease, doctor;

                // split using '|'
                int pos1 = line.find('|');
                int pos2 = line.find('|', pos1 + 1);
                int pos3 = line.find('|', pos2 + 1);
                int pos4 = line.find('|', pos3 + 1);

                id = line.substr(0, pos1);
                name = line.substr(pos1 + 1, pos2 - pos1 - 1);
                age = line.substr(pos2 + 1, pos3 - pos2 - 1);
                disease = line.substr(pos3 + 1, pos4 - pos3 - 1);
                doctor = line.substr(pos4 + 1);

                cout << setw(10) << id
                     << setw(20) << name
                     << setw(6)  << age
                     << setw(20) << disease
                     << setw(15) << doctor << endl;
            }
        }

        // ---------- READ EMERGENCY ----------
        if (line == "EMERGENCY") {
            cout << "\n--- EMERGENCY CASES FROM FILE ---\n";
            cout << left
                 << setw(10) << "CaseID"
                 << setw(20) << "Name"
                 << setw(6)  << "Age"
                 << setw(15) << "Type"
                 << setw(15) << "Doctor"
                 << setw(8)  << "Priority" << endl;
            cout << "-------------------------------------------------------------\n";

            while (getline(file, line) && !line.empty()) {
                string caseID, name, type, doctor;
                int age, priority;

                stringstream ss(line);
                ss >> caseID >> name >> age >> type >> doctor >> priority;

                cout << setw(10) << caseID
                     << setw(20) << name
                     << setw(6)  << age
                     << setw(15) << type
                     << setw(15) << doctor
                     << setw(8)  << priority << endl;
            }
        }

        // ---------- READ DEATH RECORDS ----------
        if (line == "DEATH") {
            cout << "\n--- DEATH RECORDS FROM FILE ---\n";
            cout << left
                 << setw(12) << "ID"
                 << setw(20) << "Name"
                 << setw(12) << "Year"
                 << setw(25) << "Cause" << endl;
            cout << "-------------------------------------------------------------\n";

            while (getline(file, line) && !line.empty()) {
                string id, name, date, cause;
                stringstream ss(line);
                ss >> id >> name >> date >> cause;

                cout << setw(12) << id
                     << setw(20) << name
                     << setw(12) << date
                     << setw(25) << cause << endl;
            }
        }
    }

    file.close();
    cout << "\n=========== END OF FILE DATA ===========\n";
}

  // MAIN MENU

int main() {
    int opt;

    do {
        cout << "\n========== HOSPITAL MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add New Patient\n";
        cout << "2. Show Patient List\n";
        cout << "3. Search Patient\n";
        cout << "4. Update Patient\n";
        cout << "5. Delete Patient\n";
        cout << "6. Add Emergency Case\n";
        cout << "7. Show Emergency Cases\n";
        cout << "8. Add Death Record\n";
        cout << "9. Search Death Records\n";
        cout << "10. Show All Death Records\n";
        cout << "11. Exit & Save All Data\n";
        cout << "12. Read All Data\n";
        cout << "Enter option: ";
        cin >> opt;
        cin.ignore();

        switch (opt) {
            case 1: addPatient(); break;
            case 2: showPatients(); break;
            case 3: searchPatient(); break;
            case 4: updatePatient(); break;
            case 5: deletePatient(); break;
            case 6: addEmergency(); break;
            case 7: showEmergency(); break;
            case 8: addDeathRecord(); break;
            case 9: searchDeathRecords(); break;
            case 10: showDeathRecords(); break;

            case 11:
                cout << "\nSaving all data into database.txt...\n";
                saveAllData();
                cout << "All data saved successfully. Exiting program...\n";
                break;
                case 12:
                readdata();
                cout<<"Read data \n";
                

            default:
                cout << "Invalid Option!\n";
        }

        if (opt != 11) pause();

    } while (opt != 11);

    return 0;
}