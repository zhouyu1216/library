#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
using namespace std;

class Book {
protected:
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
    virtual ~Book();    // 虚析构函数

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

    // 纯虚函数，Book 变为抽象类，子类必须重写
    virtual void display() const = 0;

    static bool isValidIsbn(const string& isbn);
};

#endif