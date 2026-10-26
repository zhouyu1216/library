#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "Book.h"

class Magazine : public Book {
private:
    int issueNumber;
    string month;

public:
    Magazine();
    Magazine(const string& title, const string& isbn, const string& publisher,
             double price, int pages, bool available,
             int issueNumber, const string& month);

    void setIssueNumber(int issueNumber);
    void setMonth(const string& month);
    int getIssueNumber() const;
    string getMonth() const;

    void display() const override;
};

#endif