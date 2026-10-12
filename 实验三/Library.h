#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>
#include "Book.h"
#include "User.h"
using namespace std;

class Library {
private:
    string name;
    vector<Book*> books;   // 基类指针，统一管理不同子类对象
    vector<User*> users;   // 基类指针，统一管理不同子类对象

public:
    Library();
    Library(const string& name);
    ~Library();   // 释放所有 new 出来的对象

    void setName(const string& name);
    string getName() const;

    // 图书管理
    void addBook(Book* book);
    bool removeBook(const string& isbn);
    Book* findBook(const string& isbn);
    void displayAllBooks() const;
    int getBookCount() const;

    // 用户管理
    void addUser(User* user);
    User* findUser(const string& id);
    void displayAllUsers() const;
    int getUserCount() const;
};

#endif