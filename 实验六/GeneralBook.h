#ifndef GENERALBOOK_H
#define GENERALBOOK_H

#include "Book.h"

class GeneralBook : public Book {
private:
    string author;
    string category;

public:
    GeneralBook();
    GeneralBook(const string& title, const string& isbn, const string& publisher,
                double price, int pages, bool available,
                const string& author, const string& category);

    void setAuthor(const string& author);
    void setCategory(const string& category);
    string getAuthor() const;
    string getCategory() const;

    void display() const override;
};

#endif