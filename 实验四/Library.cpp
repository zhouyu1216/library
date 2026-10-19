#include "Library.h"
#include <iostream>
#include <algorithm>

Library::Library() : name("Unknown Library") {}

Library::Library(const string& name) : name(name) {}

Library::~Library() {
    // 释放所有 new 出来的 Book 和 User 对象
    for (auto b : books) delete b;
    for (auto u : users) delete u;
    books.clear();
    users.clear();
}

void Library::setName(const string& name) { this->name = name; }
string Library::getName() const { return name; }

// ===== 图书管理 =====

void Library::addBook(Book* book) {
    if (book == nullptr) return;
    books.push_back(book);
    cout << "[Added] \"" << book->getTitle() << "\" added." << endl;
}

bool Library::removeBook(const string& isbn) {
    auto it = find_if(books.begin(), books.end(),
        [&isbn](Book* b) { return b->getIsbn() == isbn; });
    if (it == books.end()) {
        cout << "[Remove Failed] ISBN " << isbn << " not found." << endl;
        return false;
    }
    cout << "[Removed] \"" << (*it)->getTitle() << "\" removed." << endl;
    delete *it;      // 释放内存
    books.erase(it);
    return true;
}

Book* Library::findBook(const string& isbn) {
    for (auto b : books) {
        if (b->getIsbn() == isbn) return b;
    }
    return nullptr;
}

void Library::displayAllBooks() const {
    cout << "========== " << name << " Book List ==========" << endl;
    if (books.empty()) {
        cout << "(No books)" << endl;
    } else {
        for (auto b : books) {
            b->display();    // 虚函数，多态调用
        }
    }
    cout << "Total: " << books.size() << " books." << endl;
    cout << "=============================================" << endl;
}

int Library::getBookCount() const { return books.size(); }

// ===== 用户管理 =====

void Library::addUser(User* user) {
    if (user == nullptr) return;
    users.push_back(user);
    cout << "[Added] User \"" << user->getName() << "\" added." << endl;
}

User* Library::findUser(const string& id) {
    for (auto u : users) {
        if (u->getId() == id) return u;
    }
    return nullptr;
}

void Library::displayAllUsers() const {
    cout << "========== " << name << " User List ==========" << endl;
    if (users.empty()) {
        cout << "(No users)" << endl;
    } else {
        for (auto u : users) {
            u->display();    // 虚函数，多态调用
        }
    }
    cout << "Total: " << users.size() << " users." << endl;
    cout << "=============================================" << endl;
}

int Library::getUserCount() const { return users.size(); }