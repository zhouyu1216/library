#include "Library.h"
#include <iostream>
#include <algorithm>

Library::Library() : name("Unknown Library") {}

Library::Library(const string& name) : name(name) {}

void Library::setName(const string& name) { this->name = name; }
string Library::getName() const { return name; }

void Library::addBook(const Book& book) {
    books.push_back(book);
    cout << "[Added] \"" << book.getTitle() << "\" added to " << name << endl;
}

bool Library::removeBook(const string& isbn) {
    auto it = find_if(books.begin(), books.end(),
        [&isbn](const Book& b) { return b.getIsbn() == isbn; });
    if (it == books.end()) {
        cout << "[Remove Failed] ISBN " << isbn << " not found." << endl;
        return false;
    }
    cout << "[Removed] \"" << it->getTitle() << "\" removed." << endl;
    books.erase(it);
    return true;
}

Book* Library::findBook(const string& isbn) {
    for (auto& b : books) {
        if (b.getIsbn() == isbn) return &b;
    }
    return nullptr;
}

void Library::displayAll() const {
    cout << "========== " << name << " Book List ==========" << endl;
    if (books.empty()) {
        cout << "(No books)" << endl;
    } else {
        for (const auto& b : books) {
            b.display();
        }
    }
    cout << "Total: " << books.size() << " books." << endl;
    cout << "=============================================" << endl;
}

int Library::getBookCount() const { return books.size(); }