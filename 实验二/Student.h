#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Book.h"
using namespace std;

class Student {
private:
    string id;
    string name;
    string department;
    int maxBorrow;
    int borrowedCount;
    vector<string> borrowedIsbns;

public:
    Student();
    Student(const string& id, const string& name, const string& department, int maxBorrow);

    void setId(const string& id);
    void setName(const string& name);
    void setDepartment(const string& department);
    void setMaxBorrow(int maxBorrow);

    string getId() const;
    string getName() const;
    string getDepartment() const;
    int getMaxBorrow() const;
    int getBorrowedCount() const;

    bool borrowBook(Book* book);
    bool returnBook(Book* book);

    void display() const;
};

#endif