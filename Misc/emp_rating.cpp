#include <iostream>
#include <string>
#include <vector>

class Employee {
private:
    std::string name;
    int employeeID;
    int numTasks;
    std::vector<int> taskRatings;

public:
    Employee(const std::string& empName, int empID)
        : name(empName), employeeID(empID), numTasks(0) {}

    void assignTask(int rating) {
        taskRatings.push_back(rating);
        numTasks++;
    }

    void displayDetails() const {
        std::cout << "Employee Name: " << name << std::endl;
        std::cout << "Employee ID: " << employeeID << std::endl;
        std::cout << "Number of Tasks: " << numTasks << std::endl;
        std::cout << "Task Ratings: ";
        for (const auto& rating : taskRatings) {
            std::cout << rating << " ";
        }
        std::cout << std::endl;
    }
};

int main () {
    Employee emp1("John", 1);
    emp1.assignTask(5);
    emp1.assignTask(4);
    emp1.assignTask(3);
    emp1.displayDetails();

    Employee emp2("Jane", 2);
    emp2.assignTask(5);
    emp2.assignTask(5);
    emp2.assignTask(5);
    emp2.displayDetails();

    return 0;
}