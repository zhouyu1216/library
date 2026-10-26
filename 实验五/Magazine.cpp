#include "Magazine.h"

Magazine::Magazine()
    : Book(), issueNumber(0), month("Unknown") {}

Magazine::Magazine(const string& title, const string& isbn, const string& publisher,
                   double price, int pages, bool available,
                   int issueNumber, const string& month)
    : Book(title, isbn, publisher, price, pages, available),
      issueNumber(issueNumber), month(month) {}

void Magazine::setIssueNumber(int issueNumber) { this->issueNumber = issueNumber; }
void Magazine::setMonth(const string& month) { this->month = month; }
int Magazine::getIssueNumber() const { return issueNumber; }
string Magazine::getMonth() const { return month; }

void Magazine::display() const {
    cout << "======== Magazine Info ========" << endl;
    cout << "Title    : " << title << endl;
    cout << "ISBN     : " << isbn << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Price    : " << price << " CNY" << endl;
    cout << "Pages    : " << pages << endl;
    cout << "Issue No.: " << issueNumber << endl;
    cout << "Month    : " << month << endl;
    cout << "Status   : " << (available ? "Available" : "Borrowed") << endl;
    cout << "===============================" << endl;
}