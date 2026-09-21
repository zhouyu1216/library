#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string title;
    string isbn;
    string publisher;
    double price;
    int pages;
    bool available;

public:
    Book();
    Book(const string& title, const string& isbn, const string& publisher,
         double price, int pages, bool available);

    void setTitle(const string& title);
    void setPublisher(const string& publisher);
    void setPrice(double price);
    void setPages(int pages);
    void setAvailable(bool available);
    bool setIsbn(const string& isbn);

    string getTitle() const;
    string getIsbn() const;
    string getPublisher() const;
    double getPrice() const;
    int getPages() const;
    bool isAvailable() const;

    bool borrow();
    void giveBack();

    void display() const;
    static bool isValidIsbn(const string& isbn);
};

#endif