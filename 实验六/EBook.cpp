#include "EBook.h"

EBook::EBook()
    : Book(), fileSize(0.0), format("Unknown") {}

EBook::EBook(const string& title, const string& isbn, const string& publisher,
             double price, int pages, bool available,
             double fileSize, const string& format)
    : Book(title, isbn, publisher, price, pages, available),
      fileSize(fileSize), format(format) {}

void EBook::setFileSize(double fileSize) { this->fileSize = fileSize; }
void EBook::setFormat(const string& format) { this->format = format; }
double EBook::getFileSize() const { return fileSize; }
string EBook::getFormat() const { return format; }

void EBook::display() const {
    cout << "========= EBook Info ==========" << endl;
    cout << "Title    : " << title << endl;
    cout << "ISBN     : " << isbn << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Price    : " << price << " CNY" << endl;
    cout << "Pages    : " << pages << endl;
    cout << "File Size: " << fileSize << " MB" << endl;
    cout << "Format   : " << format << endl;
    cout << "Status   : " << (available ? "Available" : "Borrowed") << endl;
    cout << "===============================" << endl;
}