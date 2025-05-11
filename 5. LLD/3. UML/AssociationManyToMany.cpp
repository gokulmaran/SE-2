#include <bits/stdc++.h>
using namespace std;

// Class for Student forward declared
class Student;

// Class for Passport
class Passport {
private:
    string passportNumber;
    vector<Student*> students; // Many-to-many: Passport can be associated with multiple Students

public:
    Passport(string passportNumber) {
        this->passportNumber = passportNumber;
    }

    void addStudent(Student* student) {
        students.push_back(student);
    }

    string getPassport() {
        return passportNumber;
    }

    void displayStudents();
};

// Class for Student
class Student {
private:
    string name;
    vector<Passport*> passports; // Student can have multiple passports

public:
    Student(string name) {
        this->name = name;
    }

    void addPassport(Passport* passport) {
        passports.push_back(passport);
    }

    string getName() {
        return name;
    }

    void displayDetails() {
        cout << "Student name: " << name << endl;
        cout << "Passport Numbers: " << endl;
        if (passports.empty()) {
            cout << "  No passports assigned." << endl;
        } else {
            for (auto passport : passports) {
                cout << "  Passport Number: " << passport->getPassport() << endl;
            }
        }
    }
};

// Definition of displayStudents() now that Student is fully defined
void Passport::displayStudents() {
    cout << "Passport Number: " << passportNumber << endl;
    cout << "Associated Students: " << endl;
    if (students.empty()) {
        cout << "  No students assigned." << endl;
    } else {
        for (auto student : students) {
            cout << "  Student Name: " << student->getName() << endl;
        }
    }
}

// Main function
int main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    Passport p1("BNGTPG6132Q");
    Passport p2("XYZABC9876P");

    Student s1("Gokul");
    Student s2("Alice");

    s1.addPassport(&p1);
    s1.addPassport(&p2);
    s2.addPassport(&p1);
    s2.addPassport(&p2);

    p1.addStudent(&s1);
    p1.addStudent(&s2);
    p2.addStudent(&s1);
    p2.addStudent(&s2);

    cout << "Student Details:" << endl;
    s1.displayDetails();
    cout << endl;
    s2.displayDetails();
    cout << endl;

    cout << "Passport Details:" << endl;
    p1.displayStudents();
    cout << endl;
    p2.displayStudents();

    return 0;
}
