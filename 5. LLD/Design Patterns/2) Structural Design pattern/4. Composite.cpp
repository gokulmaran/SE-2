/*concept
The Composite Pattern is a structural design pattern that lets clients treat individual objects and compositions of objects uniformly.

Useful for representing tree structures, such as UI components, file systems, and organizational hierarchies.
Helps manage complex hierarchical objects without writing special-case code.
====================================================*/
#include <iostream>
#include <vector>

using namespace std;

// Base Component
class EmployeeComponent {
public:
    virtual void displayInfo() = 0;
    virtual double calculateSalary() = 0;
    virtual ~EmployeeComponent() {}
};

// Leaf: Employee
class Employee : public EmployeeComponent {
private:
    string name;
    double salary;

public:
    Employee(string empName, double empSalary) : name(empName), salary(empSalary) {}

    void displayInfo() override {
        cout << "- Employee: " << name << " | Salary: Rs." << salary << endl;
    }

    double calculateSalary() override {
        return salary;
    }
};

// Composite: Team/Department
class OrganizationUnit : public EmployeeComponent {
private:
    string name;
    vector<EmployeeComponent*> members;

public:
    OrganizationUnit(string unitName) : name(unitName) {}

    void addMember(EmployeeComponent* member) {
        members.push_back(member);
    }

    void displayInfo() override {
        cout << "[Unit]: " << name << endl;
        for (auto member : members) {
            member->displayInfo();
        }
    }

    double calculateSalary() override {
        double totalSalary = 0.0;
        for (auto member : members) {
            totalSalary += member->calculateSalary();
        }
        return totalSalary;
    }

    // Destructor to free memory
    ~OrganizationUnit() {
        for (auto member : members) {
            delete member;
        }
    }
};

// Client Code
int main() {
    EmployeeComponent* keerti = new Employee("Keerti", 100.0);
    EmployeeComponent* amit = new Employee("Amit", 200.0);
    EmployeeComponent* bob = new Employee("Bob", 50.0);

    OrganizationUnit* sales = new OrganizationUnit("Sales Team");
    sales->addMember(keerti);
    sales->addMember(amit);

    OrganizationUnit* marketing = new OrganizationUnit("Marketing Team");
    marketing->addMember(bob);

    OrganizationUnit* headOffice = new OrganizationUnit("Head Office");
    headOffice->addMember(sales);
    headOffice->addMember(marketing);

    headOffice->displayInfo();
    cout << "Total Salary for the Organization: Rs." << headOffice->calculateSalary() << endl;

    // Manually delete allocated memory
    delete headOffice;

    return 0;
}
