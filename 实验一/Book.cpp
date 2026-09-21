#include "Book.h"
#include <iostream>
#include <cctype>

Book::Book()
    : title("未知书名"), isbn("0000000000"), publisher("未知出版社"),
      price(0.0), pages(0), available(true) {}


Book::Book(const string& title, const string& isbn, const string& publisher,
           double price, int pages, bool available)
    : title(title), publisher(publisher), price(price), pages(pages), available(available) {

    if (isValidIsbn(isbn)) {
        this->isbn = isbn;
    } else {
        this->isbn = "0000000000";
        cout << "[警告] ISBN 不合法，已使用默认值。" << endl;
    }
}


void Book::setTitle(const string& title) {
    this->title = title;
}

void Book::setPublisher(const string& publisher) {
    this->publisher = publisher;
}

void Book::setPrice(double price) {
    if (price >= 0) {
        this->price = price;
    } else {
        cout << "[警告] 价格不能为负数。" << endl;
    }
}

void Book::setPages(int pages) {
    if (pages >= 0) {
        this->pages = pages;
    } else {
        cout << "[警告] 页数不能为负数。" << endl;
    }
}

void Book::setAvailable(bool available) {
    this->available = available;
}

bool Book::setIsbn(const string& isbn) {
    if (isValidIsbn(isbn)) {
        this->isbn = isbn;
        return true;
    }
    cout << "[警告] ISBN 不合法，修改失败。" << endl;
    return false;
}


string Book::getTitle() const { return title; }
string Book::getIsbn() const { return isbn; }
string Book::getPublisher() const { return publisher; }
double Book::getPrice() const { return price; }
int Book::getPages() const { return pages; }
bool Book::isAvailable() const { return available; }


void Book::display() const {
    cout << "========== 图书信息 ==========" << endl;
    cout << "书名    : " << title << endl;
    cout << "ISBN    : " << isbn << endl;
    cout << "出版社  : " << publisher << endl;
    cout << "价格    : " << price << " 元" << endl;
    cout << "页数    : " << pages << " 页" << endl;
    cout << "在馆状态: " << (available ? "可借" : "不可借") << endl;
    cout << "==============================" << endl;
}


bool Book::isValidIsbn(const string& isbn) {
    int len = isbn.length();
    if (len != 10 && len != 13) {
        return false;
    }

    if (len == 10) {
        for (int i = 0; i < 9; i++) {
            if (!isdigit(isbn[i])) return false;
        }
        char last = isbn[9];
        if (!isdigit(last) && last != 'X' && last != 'x') {
            return false;
        }
    } else {
        for (int i = 0; i < 13; i++) {
            if (!isdigit(isbn[i])) return false;
        }
        string prefix = isbn.substr(0, 3);
        if (prefix != "978" && prefix != "979") {
            return false;
        }
    }
    return true;
}
