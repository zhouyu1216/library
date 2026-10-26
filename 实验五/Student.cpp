#include "Student.h"

Student::Student()
    : User(), major("Unknown") {}

Student::Student(const string& id, const string& name, const string& department,
                 int maxBorrow, const string& major)
    : User(id, name, department, maxBorrow), major(major) {}

void Student::setMajor(const string& major) { this->major = major; }
string Student::getMajor() const { return major; }

void Student::display() const {
    cout << "========== Student Info ==========" << endl;
    cout << "ID       : " << id << endl;
    cout << "Name     : " << name << endl;
    cout << "Dept     : " << department << endl;
    cout << "Major    : " << major << endl;
    cout << "Max      : " << maxBorrow << endl;
    cout << "Borrowed : " << borrowedCount << endl;
    cout << "==================================" << endl;
}