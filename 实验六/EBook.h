#ifndef EBOOK_H
#define EBOOK_H

#include "Book.h"

class EBook : public Book {
private:
    double fileSize;    // 文件大小 MB
    string format;      // 格式

public:
    EBook();
    EBook(const string& title, const string& isbn, const string& publisher,
          double price, int pages, bool available,
          double fileSize, const string& format);

    void setFileSize(double fileSize);
    void setFormat(const string& format);
    double getFileSize() const;
    string getFormat() const;

    void display() const override;
};

#endif