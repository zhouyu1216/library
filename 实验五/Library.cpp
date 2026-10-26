#include "Library.h"
#include <iostream>
#include <algorithm>

Library::Library() : name("Unknown Library") {}

Library::Library(const string& name) : name(name) {}

Library::~Library() {
    // 遍历模板容器，释放内存
    for (auto b : bookRepo.getAll()) delete b;
    for (auto u : userRepo.getAll()) delete u;
}

void Library::setName(const string& name) { this->name = name; }
string Library::getName() const { return name; }

// ===== 图书管理 =====

void Library::addBook(Book* book) {
    if (book == nullptr) return;
    bookRepo.add(book);   // 模板的添加方法
    cout << "[Added] \"" << book->getTitle() << "\" added." << endl;
}

bool Library::removeBook(const string& isbn) {
    const auto& books = bookRepo.getAll();
    for (int i = 0; i < books.size(); i++) {
        if (books[i]->getIsbn() == isbn) {
            cout << "[Removed] \"" << books[i]->getTitle() << "\" removed." << endl;
            delete books[i];         // 释放内存
            bookRepo.remove(i);      // 模板的删除方法
            return true;
        }
    }
    cout << "[Remove Failed] ISBN " << isbn << " not found." << endl;
    return false;
}

Book* Library::findBook(const string& isbn) {
    for (auto b : bookRepo.getAll()) {
        if (b->getIsbn() == isbn) return b;
    }
    return nullptr;
}

void Library::displayAllBooks() const {
    cout << "========== " << name << " Book List ==========" << endl;
    if (bookRepo.size() == 0) {
        cout << "(No books)" << endl;
    } else {
        for (auto b : bookRepo.getAll()) {
            b->display();
        }
    }
    cout << "Total: " << bookRepo.size() << " books." << endl;
    cout << "=============================================" << endl;
}

int Library::getBookCount() const { return bookRepo.size(); }

// ===== 用户管理 =====

void Library::addUser(User* user) {
    if (user == nullptr) return;
    userRepo.add(user);
    cout << "[Added] User \"" << user->getName() << "\" added." << endl;
}

User* Library::findUser(const string& id) {
    for (auto u : userRepo.getAll()) {
        if (u->getId() == id) return u;
    }
    return nullptr;
}

void Library::displayAllUsers() const {
    cout << "========== " << name << " User List ==========" << endl;
    if (userRepo.size() == 0) {
        cout << "(No users)" << endl;
    } else {
        for (auto u : userRepo.getAll()) {
            u->display();
        }
    }
    cout << "Total: " << userRepo.size() << " users." << endl;
    cout << "=============================================" << endl;
}

int Library::getUserCount() const { return userRepo.size(); }