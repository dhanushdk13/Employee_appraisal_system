#include <iostream>
#include <string>

class Employee {
public:
    std::string name;
    int ID;
    double performanceRating;

    // Constructor
    Employee(const std::string& name, int ID, double performanceRating)
        : name(name), ID(ID), performanceRating(performanceRating) {}
};

// Compare function for performance rating
template <typename T1, typename T2>
bool compareByPerformanceRating(const T1& emp1, const T2& emp2) {
    return emp1.performanceRating > emp2.performanceRating;
}

// Compare function for name
template <typename T1, typename T2>
bool compareByName(const T1& emp1, const T2& emp2) {
    return emp1.name < emp2.name;
}

// Compare function for ID
template <typename T1, typename T2>
bool compareByID(const T1& emp1, const T2& emp2) {
    return emp1.ID < emp2.ID;
}

int main() {
    Employee emp1("John", 1, 4.5);
    Employee emp2("Alice", 2, 3.8);

    // Compare employees by performance rating
    if (compareByPerformanceRating(emp1, emp2)) {
        std::cout << emp1.name << " has a higher performance rating than " << emp2.name << std::endl;
    } else {
        std::cout << emp2.name << " has a higher performance rating than " << emp1.name << std::endl;
    }

    // Compare employees by name
    if (compareByName(emp1, emp2)) {
        std::cout << emp1.name << " comes before " << emp2.name << " alphabetically" << std::endl;
    } else {
        std::cout << emp2.name << " comes before " << emp1.name << " alphabetically" << std::endl;
    }

    // Compare employees by ID
    if (compareByID(emp1, emp2)) {
        std::cout << emp1.name << " has a lower ID than " << emp2.name << std::endl;
    } else {
        std::cout << emp2.name << " has a lower ID than " << emp1.name << std::endl;
    }

    return 0;
}
