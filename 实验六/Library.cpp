#include "Library.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "GeneralBook.h"
#include "Magazine.h"
#include "EBook.h"

Library::Library() : name("Unknown Library") {}

Library::Library(const string& name) : name(name) {}

Library::~Library() {
    for (auto b : bookRepo.getAll()) delete b;
    for (auto u : userRepo.getAll()) delete u;
}

void Library::setName(const string& name) { this->name = name; }
string Library::getName() const { return name; }

// ===== 图书管理 =====

void Library::addBook(Book* book) {
    if (book == nullptr) return;
    bookRepo.add(book);
    cout << "[Added] \"" << book->getTitle() << "\" added." << endl;
}

bool Library::removeBook(const string& isbn) {
    const auto& books = bookRepo.getAll();
    for (int i = 0; i < books.size(); i++) {
        if (books[i]->getIsbn() == isbn) {
            cout << "[Removed] \"" << books[i]->getTitle() << "\" removed." << endl;
            delete books[i];
            bookRepo.remove(i);
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

// ===== 实验六：文件存储实现 =====

void Library::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "[Error] Cannot open file for writing: " << filename << endl;
        return;
    }

    // 先写入图书总数
    outFile << bookRepo.size() << endl;

    // 写入每本书（第一列写类型标签）
    for (auto b : bookRepo.getAll()) {
        if (dynamic_cast<GeneralBook*>(b)) {
            GeneralBook* gb = dynamic_cast<GeneralBook*>(b);
            outFile << "GeneralBook " 
                    << b->getTitle() << " " << b->getIsbn() << " " << b->getPublisher() << " "
                    << b->getPrice() << " " << b->getPages() << " " << b->isAvailable() << " "
                    << gb->getAuthor() << " " << gb->getCategory() << endl;
        } 
        else if (dynamic_cast<Magazine*>(b)) {
            Magazine* mg = dynamic_cast<Magazine*>(b);
            outFile << "Magazine " 
                    << b->getTitle() << " " << b->getIsbn() << " " << b->getPublisher() << " "
                    << b->getPrice() << " " << b->getPages() << " " << b->isAvailable() << " "
                    << mg->getIssueNumber() << " " << mg->getMonth() << endl;
        }
        else if (dynamic_cast<EBook*>(b)) {
            EBook* eb = dynamic_cast<EBook*>(b);
            outFile << "EBook " 
                    << b->getTitle() << " " << b->getIsbn() << " " << b->getPublisher() << " "
                    << b->getPrice() << " " << b->getPages() << " " << b->isAvailable() << " "
                    << eb->getFileSize() << " " << eb->getFormat() << endl;
        }
    }

    outFile.close();
    cout << "[Success] Data saved to " << filename << endl;
}

void Library::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "[Info] No existing data file found. Starting fresh." << endl;
        return;
    }

    // 清空当前内存数据
    for (auto b : bookRepo.getAll()) delete b;
    bookRepo.clear();
    for (auto u : userRepo.getAll()) delete u;
    userRepo.clear();

    int bookCount;
    inFile >> bookCount;

    for (int i = 0; i < bookCount; i++) {
        string type, title, isbn, publisher;
        double price;
        int pages;
        bool available;

        inFile >> type >> title >> isbn >> publisher >> price >> pages >> available;

        if (type == "GeneralBook") {
            string author, category;
            inFile >> author >> category;
            addBook(new GeneralBook(title, isbn, publisher, price, pages, available, author, category));
        }
        else if (type == "Magazine") {
            int issueNumber;
            string month;
            inFile >> issueNumber >> month;
            addBook(new Magazine(title, isbn, publisher, price, pages, available, issueNumber, month));
        }
        else if (type == "EBook") {
            double fileSize;
            string format;
            inFile >> fileSize >> format;
            addBook(new EBook(title, isbn, publisher, price, pages, available, fileSize, format));
        }
    }

    inFile.close();
    cout << "[Success] Data loaded from " << filename << endl;
}