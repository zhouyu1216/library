#pragma once
#include <string>
using namespace std;

class Book {
private:
    string title;       // 书名
    string isbn;        // ISBN
    string publisher;   // 出版社
    double price;       // 价格
    int pages;          // 页数
    bool available;     // 是否可借

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

    void display() const;

    static bool isValidIsbn(const string& isbn);
};
