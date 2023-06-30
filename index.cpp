#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

//Tech Lead Login Function




struct TechLead {
    string employeeId;
    string name;
    string password;
};

string trim(const string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");
    if (start == string::npos || end == string::npos) {
        return "";
    }
    return str.substr(start, end - start + 1);
}

// Function to check Tech Lead login credentials
bool loginTechLead(const string& employeeId, const string& password) {
    ifstream file("data/tech_leads.txt");
    if (!file) {
        cout << "Error opening tech_leads.txt file. Unable to perform login." << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string id, firstName, pass;
        ss >> id >> firstName >> pass;

        if (id == employeeId && pass == password) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Function to check Manager login credentials
bool loginManager(const string& employeeId, const string& password) {
    ifstream file("data/manager.txt");
    if (!file) {
        cout << "Error opening managers.txt file. Unable to perform login." << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string id, firstName, pass;
        ss >> id >> firstName >> pass;

        if (id == employeeId && pass == password) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

bool loginHR(const string& employeeId, const string& password) {
    ifstream file("data/hr.txt");
    if (!file) {
        cout << "Error opening managers.txt file. Unable to perform login." << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string id, firstName, pass;
        ss >> id >> firstName >> pass;

        if (id == employeeId && pass == password) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}



void displayMainMenu() {
    cout << "----- Employee Appraisal System -----" << endl;
    cout << "1. Login" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter your choice: ";
}

void displayLoginSubMenu() {
    cout << "\n----- Login -----" << endl;
    cout << "a. Tech Lead" << endl;
    cout << "b. Engineering Manager" << endl;
    cout << "c. Human Resources" << endl;
    cout << "Enter your choice: ";
}

void displayTechLeadSubMenu() {
    cout << "\n----- Tech Lead Menu -----" << endl;
    cout << "a. Rate Yourself" << endl;
    cout << "b. View Your Final Ratings and Hike" << endl;
    cout << "c. Exit" << endl;
    cout << "Enter your choice: ";
}

void displayEngineeringManagerSubMenu() {
    cout << "\n----- Engineering Manager Menu -----" << endl;
    cout << "a. Tech Lead Ratings" << endl;
    cout << "b. Distribution Chart" << endl;
    cout << "c. Decide Tasks for Tech Lead" << endl;
    cout << "d. Exit" << endl;
    cout << "Enter your choice: ";
}

void displayHumanResourcesSubMenu() {
    cout << "\n----- Human Resources Menu -----" << endl;
    cout << "a. View Self Ratings of Tech Leads" << endl;
    cout << "b. View Ratings Provided by Manager" << endl;
    cout << "c. Set Final Ratings" << endl;
    cout << "d. Exit" << endl;
    cout << "Enter your choice: ";
}

void handleTechLeadSubMenu() {
    char choice;
    do {
        displayTechLeadSubMenu();
        cin >> choice;
        // Add your code here to handle the Tech Lead submenu options
        // For example:
        switch (choice) {
            case 'a':
                // Handle Rate Yourself
                break;
            case 'b':
                // Handle View Your Final Ratings and Hike
                break;
            case 'c':
                cout << "Exiting Tech Lead Menu. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 'c');
}

/* void handleEngineeringManagerSubMenuOption(char subChoice) {
    switch (subChoice) {
        case 'a':
            cout << "Tech Lead Ratings selected." << endl;
            // Add logic to handle Tech Lead Ratings
            break;
        case 'b':
            cout << "Distribution Chart selected." << endl;
            // Add logic to handle Distribution Chart
            break;
        case 'c':
            cout << "Decide Tasks for Tech Lead selected." << endl;
            // Add logic to handle Decide Tasks for Tech Lead
            break;
        case 'd':
            cout << "Exiting Engineering Manager Menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
} */


void handleEMSubMenu() {
    char choice;
    do {
        displayEngineeringManagerSubMenu();
        cin >> choice;
        // Add your code here to handle the Tech Lead submenu options
        // For example:
        switch (choice) {
        case 'a':
            cout << "Tech Lead Ratings selected." << endl;
            // Add logic to handle Tech Lead Ratings
            break;
        case 'b':
            cout << "Distribution Chart selected." << endl;
            // Add logic to handle Distribution Chart
            break;
        case 'c':
            cout << "Decide Tasks for Tech Lead selected." << endl;
            // Add logic to handle Decide Tasks for Tech Lead
            break;
        case 'd':
            cout << "Exiting Engineering Manager Menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 'd');
}

/* 
void handleHumanResourcesSubMenuOption(char subChoice) {
    switch (subChoice) {
        case 'a':
            cout << "View Self Ratings of Tech Leads selected." << endl;
            // Add logic to handle View Self Ratings of Tech Leads
            break;
        case 'b':
            cout << "View Ratings Provided by Manager selected." << endl;
            // Add logic to handle View Ratings Provided by Manager
            break;
        case 'c':
            cout << "Set Final Ratings selected." << endl;
            // Add logic to handle Set Final Ratings
            break;
        case 'd':
            cout << "Exiting Human Resources Menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
} */


void handleHRSubMenu() {
    char choice;
    do {
        displayHumanResourcesSubMenu();
        cin >> choice;
        // Add your code here to handle the Tech Lead submenu options
        // For example:
        switch (choice) {
        case 'a':
            cout << "View Self Ratings of Tech Leads selected." << endl;
            // Add logic to handle View Self Ratings of Tech Leads
            break;
        case 'b':
            cout << "View Ratings Provided by Manager selected." << endl;
            // Add logic to handle View Ratings Provided by Manager
            break;
        case 'c':
            cout << "Set Final Ratings selected." << endl;
            // Add logic to handle Set Final Ratings
            break;
        case 'd':
            cout << "Exiting Human Resources Menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 'd');
}




int main() {
    int choice;
    char subChoice;
    string employeeId;
    string password;
    
    do {
        displayMainMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: {
                displayLoginSubMenu();
                cin >> subChoice;
                
                switch (subChoice) {
                    case 'a': {
                        cout << "\n----- Tech Lead Login -----" << endl;
                        cout << "Employee ID: ";
                        cin >> employeeId;
                        cout << "Password: ";
                        cin >> password;

                        if (loginTechLead(employeeId, password)) {
                            cout << "Login successful. Welcome, Tech Lead" << endl;
                            handleTechLeadSubMenu();
                            // Handle Tech Lead submenu options
                        } else {
                            cout << "Invalid credentials. Login failed." << endl;
                        }
                        break;
}
                    case 'b':
                        cout << "\n----- Engineering Manager Login -----" << endl;
                        cout << "Employee ID: ";
                        cin >> employeeId;
                        cout << "Password: ";
                        cin >> password;

                        if (loginManager(employeeId, password)) {
                            cout << "Login successful. Welcome, Manager" << endl;
                            handleEMSubMenu();
                            // Handle Tech Lead submenu options
                        } else {
                            cout << "Invalid credentials. Login failed." << endl;
                        }
                        break;
                    case 'c':
                        cout << "\n----- HR Login -----" << endl;
                        cout << "Employee ID: ";
                        cin >> employeeId;
                        cout << "Password: ";
                        cin >> password;

                        if (loginManager(employeeId, password)) {
                            cout << "Login successful. Welcome, HR" << endl;
                            handleHRSubMenu();
                            // Handle Tech Lead submenu options
                        } else {
                            cout << "Invalid credentials. Login failed." << endl;
                        }
                        break;
                }
                
                break;
            }
                
            case 2:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 2);
    
    return 0;
}
