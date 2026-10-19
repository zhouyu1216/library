#include "Teacher.h"

Teacher::Teacher()
    : User(), title("Unknown") {}

Teacher::Teacher(const string& id, const string& name, const string& department,
                 int maxBorrow, const string& title)
    : User(id, name, department, maxBorrow), title(title) {}

void Teacher::setTitle(const string& title) { this->title = title; }
string Teacher::getTitle() const { return title; }

void Teacher::display() const {
    cout << "========== Teacher Info ==========" << endl;
    cout << "ID       : " << id << endl;
    cout << "Name     : " << name << endl;
    cout << "Dept     : " << department << endl;
    cout << "Title    : " << title << endl;
    cout << "Max      : " << maxBorrow << endl;
    cout << "Borrowed : " << borrowedCount << endl;
    cout << "==================================" << endl;
}