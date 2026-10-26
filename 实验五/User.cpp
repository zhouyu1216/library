#include "User.h"
#include <algorithm>

User::User()
    : id("000000"), name("Unknown"), department("Unknown"),
      maxBorrow(5), borrowedCount(0) {}

User::User(const string& id, const string& name, const string& department, int maxBorrow)
    : id(id), name(name), department(department),
      maxBorrow(maxBorrow), borrowedCount(0) {}

User::~User() {}

void User::setId(const string& id) { this->id = id; }
void User::setName(const string& name) { this->name = name; }
void User::setDepartment(const string& department) { this->department = department; }

void User::setMaxBorrow(int maxBorrow) {
    if (maxBorrow > 0) this->maxBorrow = maxBorrow;
    else cout << "[Warning] maxBorrow must be positive." << endl;
}

string User::getId() const { return id; }
string User::getName() const { return name; }
string User::getDepartment() const { return department; }
int User::getMaxBorrow() const { return maxBorrow; }
int User::getBorrowedCount() const { return borrowedCount; }

bool User::borrowBook(Book* book) {
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

bool User::returnBook(Book* book) {
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

// display() 的实现已经删除，因为它变成了纯虚函数