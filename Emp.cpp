#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <windows.h>
#include <limits>

using namespace std;

#ifdef _WIN32
#include <conio.h>
#else
int getch() { return getchar(); }
#endif

// Global Constants and Structure
const int MAX_EMPLOYEES = 100;

struct Employee {
    string name;
    string id;
    string address;
    int salary;
    string contact; // UPDATED: Changed from int to string
};

// Global Data
int total = 0;
Employee e[MAX_EMPLOYEES];

// --- Utility Functions ---

void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// --- Main Application Functions ---
void empdata() {
    int user = 0;
    cout << "## ➕ Add New Employee Data" << endl;
    cout << "Enter the number of employees you want to enter (Max " << (MAX_EMPLOYEES - total) << "): ";

    if (!(cin >> user) || user <= 0 || (total + user > MAX_EMPLOYEES)) {
        cout << "\n\aError: Invalid input or maximum employee limit reached (" << MAX_EMPLOYEES << ")." << endl;
        cin.clear();
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    for (int i = total; i < total + user; i++) {
        cout << "\n--- Data for Employee " << (i + 1) << " ---" << endl;

        cout << "Enter employee ID (No spaces): ";
        getline(cin, e[i].id);

        cout << "Enter employee Name: ";
        getline(cin, e[i].name);

        cout << "Enter Address: ";
        getline(cin, e[i].address);


        // --- CONTACT NUMBER (FIXED: Stored as string) ---
        cout << "Enter Contact Number: ";
        getline(cin, e[i].contact); // Now reads and stores the string directly


        // --- SALARY (Validation retained as it is a numerical value) ---
        string tempSalary;
        bool valid = false;
        while (!valid) {
            cout << "Enter Salary: ";
            getline(cin, tempSalary);
            try {
                e[i].salary = stoi(tempSalary);
                valid = true;
            } catch (const std::invalid_argument&) {
                cout << "\aInvalid input. Please enter digits only for salary." << endl;
            } catch (const std::out_of_range&) {
                cout << "\aInvalid input. Number is too large." << endl;
            }
        }
    }
    total = total + user;
    cout << "\n✅ Successfully added " << user << " employee records." << endl;
}

void show() {
    system("CLS");
    cout << "## 📊 All Employee Data" << endl;

    if (total == 0) {
        cout << "\aNo data has been entered yet." << endl;
        return;
    }

    for (int i = 0; i < total; i++) {
        cout << "\n--- Employee Record " << (i + 1) << " ---" << endl;
        cout << "ID:      " << e[i].id << endl;
        cout << "Name:    " << e[i].name << endl;
        cout << "Address: " << e[i].address << endl;
        cout << "Contact: " << e[i].contact << endl;
        cout << "Salary:  " << e[i].salary << endl;
    }
}

void search() {
    system("CLS");
    cout << "## 🔍 Search Employee by ID" << endl;
    if (total == 0) {
        cout << "\aNo data has been entered yet." << endl;
        return;
    }

    string id;
    cout << "Enter ID of the employee you want to search: ";
    cin >> id;
    clearInputBuffer();

    bool found = false;
    for (int i = 0; i < total; i++) {
        if (e[i].id == id) {
            cout << "\n✅ Record Found (Employee " << (i + 1) << ")" << endl;
            cout << "Name:    " << e[i].name << endl;
            cout << "ID:      " << e[i].id << endl;
            cout << "Address: " << e[i].address << endl;
            cout << "Contact: " << e[i].contact << endl;
            cout << "Salary:  " << e[i].salary << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\n\aNo record found with ID: " << id << endl;
    }
}

void update() {
    system("CLS");
    cout << "## 🔄 Update Employee Data" << endl;
    if (total == 0) {
        cout << "\aNo data has been entered yet." << endl;
        return;
    }

    string id;
    cout << "Enter ID of the employee you want to update: ";
    cin >> id;
    clearInputBuffer();

    bool found = false;
    for (int i = 0; i < total; i++) {
        if (e[i].id == id) {
            cout << "\n--- Old Data (Employee " << (i + 1) << ") ---" << endl;
            cout << "Name: " << e[i].name << ", ID: " << e[i].id << endl;
            cout << "\n-- Enter New Data --" << endl;

            cout << "Enter new Employee Name: ";
            getline(cin, e[i].name);

            cout << "Enter new Address: ";
            getline(cin, e[i].address);

            // UPDATED: Now uses getline for string contact number
            cout << "Enter new Contact Number: ";
            getline(cin, e[i].contact);

            cout << "Enter new Salary: ";
            while (!(cin >> e[i].salary)) {
                cout << "\aInvalid input. Please enter a number for salary: ";
                cin.clear();
                clearInputBuffer();
            }
            clearInputBuffer();

            cout << "\n✅ Employee record updated successfully." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\n\aNo record found with ID: " << id << endl;
    }
}

void del() {
    system("CLS");
    cout << "## 🗑️ Delete Employee Data" << endl;
    if (total == 0) {
        cout << "\aNo data has been entered yet." << endl;
        return;
    }

    int press;
    cout << "Press 1 to delete a specific record" << endl;
    cout << "Press 2 to delete the entire record list" << endl;

    if (!(cin >> press)) {
        cout << "\aInvalid input." << endl;
        cin.clear();
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    if (press == 1) {
        string id;
        cout << "Enter ID of the employee you want to delete: ";
        cin >> id;
        clearInputBuffer();

        bool found = false;
        for (int i = 0; i < total; i++) {
            if (e[i].id == id) {
                for (int j = i; j < total - 1; j++) {
                    e[j] = e[j + 1];
                }
                total--;
                cout << "\n✅ Record with ID " << id << " successfully deleted." << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "\n\aNo record found with ID: " << id << endl;
        }

    } else if (press == 2) {
        char confirm;
        cout << "⚠️ Are you sure you want to delete ALL records? (y/n): ";
        cin >> confirm;
        clearInputBuffer();
        if (tolower(confirm) == 'y') {
            total = 0;
            cout << "\n✅ All records have been successfully deleted." << endl;
        } else {
            cout << "\nDeletion cancelled." << endl;
        }
    } else {
        cout << "\aInvalid selection." << endl;
    }
}

// --- Main Program Loop ---

int main() {
    string username, password;
    string usrn, pswd;

    cout << "\n\n\t\t--- Employee Management System ---" << endl;
    cout << "\n\n\n\t\t****** 📝 SIGNUP ******" << endl;
    cout << "\t\tEnter new username: ";
    cin >> username;
    cout << "\t\tEnter new password: ";
    cin >> password;

    clearInputBuffer();

    cout << "\t\tCreating user ID... please wait";
    for (int i = 0; i < 3; i++) {
        cout << ".";
        Sleep(500);
    }
    cout << "\n\t\tYour ID created successfully." << endl;
    Sleep(1000);

    start:
    system("CLS");

    cout << "\n\n\t\t--- Employee Management System ---" << endl;
    cout << "\n\n\n\t\t****** 🔑 LOGIN ******" << endl;
    cout << "\t\tEnter username: ";
    cin >> usrn;
    cout << "\t\tEnter password: ";
    cin >> pswd;

    clearInputBuffer();

    if (usrn == username && pswd == password) {
        system("CLS");
        char ch;
        while (1) {
            cout << "\n\n--- Main Menu ---" << endl;
            cout << "1. Add New Employee Data" << endl;
            cout << "2. Show All Employee Data" << endl;
            cout << "3. Search Employee Data" << endl;
            cout << "4. Update Employee Data" << endl;
            cout << "5. Delete Employee Data" << endl;
            cout << "6. Logout" << endl;
            cout << "7. Exit Program" << endl;
            cout << "Enter your choice: ";

            ch = getch();
            system("CLS");

            switch (ch) {
                case '1': empdata(); break;
                case '2': show(); break;
                case '3': search(); break;
                case '4': update(); break;
                case '5': del(); break;
                case '6': goto start;
                case '7': exit(0);
                default:
                    cout << "\aInvalid Input. Press any key to return to the menu." << endl;
                    getch();
                    system("CLS");
                    break;
            }
        }
    } else {
        cout << "\t\t\aInvalid username or password. Please try again." << endl;
        Sleep(2000);
        goto start;
    }

    return 0;
}