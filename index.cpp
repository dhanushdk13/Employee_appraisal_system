#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Tech Lead Login Function
/* 
struct TechLead {
    string employeeId;
    string name;
    string password;
};

bool loginTechLead(const string& employeeId, const string& password) {
    ifstream file("data/tech_leads.txt");
    if (!file) {
        cout << "Error opening file. Unable to perform login." << endl;
        return false;
    }
    
    string line;
    while (getline(file, line)) {
        size_t pos = line.find(' ');
        if (pos == string::npos) {
            pos = line.find(',');
        }
        
        string id = line.substr(0, pos);
        string pass = line.substr(pos + 1);
        
        if (id == employeeId && pass == password) {
            file.close();
            return true;
        }
    }
} */

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

void handleTechLeadSubMenuOption(char subChoice) {
    switch (subChoice) {
        case 'a':

            cout << "Rate Yourself selected." << endl;
            // Add logic to handle Rate Yourself
            break;
        case 'b':
            cout << "View Your Final Ratings and Hike selected." << endl;
            // Add logic to handle View Your Final Ratings and Hike
            break;
        case 'c':
            cout << "Exiting Tech Lead Menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}

void handleEngineeringManagerSubMenuOption(char subChoice) {
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
}

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
}

int main() {
    int choice;
    char subChoice;
    
    do {
        displayMainMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: {
                displayLoginSubMenu();
                cin >> subChoice;
                
                switch (subChoice) {
                    case 'a':
                        displayTechLeadSubMenu();
                        cin >> subChoice;
                        handleTechLeadSubMenuOption(subChoice);
                        break;
                    case 'b':
                        displayEngineeringManagerSubMenu();
                        cin >> subChoice;
                        handleEngineeringManagerSubMenuOption(subChoice);
                        break;
                    case 'c':
                        displayHumanResourcesSubMenu();
                        cin >> subChoice;
                        handleHumanResourcesSubMenuOption(subChoice);
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
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
