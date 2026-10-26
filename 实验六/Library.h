#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>
#include "Book.h"
#include "User.h"
#include "Repository.h"
using namespace std;

class Library {
private:
    string name;
    Repository<Book*> bookRepo;   // 用模板管理图书
    Repository<User*> userRepo;   // 用模板管理用户

public:
    Library();
    Library(const string& name);
    ~Library();

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

    // ===== 实验六：文件存储 =====
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif