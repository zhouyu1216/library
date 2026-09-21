#include "Student.h"
#include <iostream>
#include <algorithm>

Student::Student()
    : id("000000"), name("Unknown"), department("Unknown"), maxBorrow(5), borrowedCount(0) {}

Student::Student(const string& id, const string& name, const string& department, int maxBorrow)
    : id(id), name(name), department(department), maxBorrow(maxBorrow), borrowedCount(0) {}

void Student::setId(const string& id) { this->id = id; }
void Student::setName(const string& name) { this->name = name; }
void Student::setDepartment(const string& department) { this->department = department; }

void Student::setMaxBorrow(int maxBorrow) {
    if (maxBorrow > 0) this->maxBorrow = maxBorrow;
    else cout << "[Warning] maxBorrow must be positive." << endl;
}

string Student::getId() const { return id; }
string Student::getName() const { return name; }
string Student::getDepartment() const { return department; }
int Student::getMaxBorrow() const { return maxBorrow; }
int Student::getBorrowedCount() const { return borrowedCount; }

bool Student::borrowBook(Book* book) {
    if (book == nullptr) {
        cout << "[Borrow Failed] Book does not exist." << endl;
        return false;
    }
    if (borrowedCount >= maxBorrow) {
        cout << "[Borrow Failed] " << name << " has reached the limit." << endl;
        return false;
    }
    if (!book->isAvailable()) {
        cout << "[Borrow Failed] \"" << book->getTitle() << "\" is already borrowed." << endl;
        return false;
    }
    if (book->borrow()) {
        borrowedIsbns.push_back(book->getIsbn());
        borrowedCount++;
        cout << "[Borrow Success] " << name << " borrowed \"" << book->getTitle() << "\"" << endl;
        return true;
    }
    return false;
}

bool Student::returnBook(Book* book) {
    if (book == nullptr) return false;
    auto it = find(borrowedIsbns.begin(), borrowedIsbns.end(), book->getIsbn());
    if (it == borrowedIsbns.end()) {
        cout << "[Return Failed] " << name << " did not borrow this book." << endl;
        return false;
    }
    borrowedIsbns.erase(it);
    borrowedCount--;
    book->giveBack();
    cout << "[Return Success] " << name << " returned \"" << book->getTitle() << "\"" << endl;
    return true;
}

void Student::display() const {
    cout << "========== Student Info ==========" << endl;
    cout << "ID       : " << id << endl;
    cout << "Name     : " << name << endl;
    cout << "Dept     : " << department << endl;
    cout << "Max      : " << maxBorrow << endl;
    cout << "Borrowed : " << borrowedCount << endl;
    if (!borrowedIsbns.empty()) {
        cout << "ISBNs    : ";
        for (const auto& isbn : borrowedIsbns) cout << isbn << " ";
        cout << endl;
    }
    cout << "==================================" << endl;
}