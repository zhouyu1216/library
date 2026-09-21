#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>
#include "Book.h"
using namespace std;

class Library {
private:
    string name;
    vector<Book> books;

public:
    Library();
    Library(const string& name);

    void setName(const string& name);
    string getName() const;

    void addBook(const Book& book);
    bool removeBook(const string& isbn);
    Book* findBook(const string& isbn);
    void displayAll() const;
    int getBookCount() const;
};

#endif