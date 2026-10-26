#include "GeneralBook.h"

GeneralBook::GeneralBook()
    : Book(), author("Unknown"), category("General") {}

GeneralBook::GeneralBook(const string& title, const string& isbn, const string& publisher,
                         double price, int pages, bool available,
                         const string& author, const string& category)
    : Book(title, isbn, publisher, price, pages, available),
      author(author), category(category) {}

void GeneralBook::setAuthor(const string& author) { this->author = author; }
void GeneralBook::setCategory(const string& category) { this->category = category; }
string GeneralBook::getAuthor() const { return author; }
string GeneralBook::getCategory() const { return category; }

void GeneralBook::display() const {
    cout << "====== General Book Info ======" << endl;
    cout << "Title    : " << title << endl;
    cout << "ISBN     : " << isbn << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Price    : " << price << " CNY" << endl;
    cout << "Pages    : " << pages << endl;
    cout << "Author   : " << author << endl;
    cout << "Category : " << category << endl;
    cout << "Status   : " << (available ? "Available" : "Borrowed") << endl;
    cout << "===============================" << endl;
}