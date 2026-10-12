#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <iostream>
#include "Book.h"
using namespace std;

class User {
protected:
    string id;
    string name;
    string department;
    int maxBorrow;
    int borrowedCount;
    vector<string> borrowedIsbns;

public:
    User();
    User(const string& id, const string& name, const string& department, int maxBorrow);
    virtual ~User();

    void setId(const string& id);
    void setName(const string& name);
    void setDepartment(const string& department);
    void setMaxBorrow(int maxBorrow);

    string getId() const;
    string getName() const;
    string getDepartment() const;
    int getMaxBorrow() const;
    int getBorrowedCount() const;

    virtual bool borrowBook(Book* book);
    virtual bool returnBook(Book* book);

    virtual void display() const;
};

#endif