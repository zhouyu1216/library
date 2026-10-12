#include "Book.h"
#include <iostream>
using namespace std;

int main() {
    Book b1;
    cout << "[Default Constructor Book]" << endl;
    b1.display();

    Book b2("C++ Primer", "9780321714114", "Addison-Wesley", 128.0, 976, true);
    cout << "\n[Overloaded Constructor Book (Valid ISBN)]" << endl;
    b2.display();

    Book b3("Invalid ISBN Test", "12345", "Test Press", 50.0, 200, true);
    cout << "\n[Invalid ISBN Test]" << endl;
    b3.display();

    cout << "\n[Modify Test]" << endl;
    b3.setTitle("Data Structures and Algorithms");
    b3.setPublisher("Higher Education Press");
    b3.setPrice(45.5);
    b3.setPages(320);
    b3.setAvailable(false);
    b3.setIsbn("9787040561234");
    b3.display();

    cout << "\n[Get Test]" << endl;
    cout << "b2 title: " << b2.getTitle() << endl;
    cout << "b2 ISBN : " << b2.getIsbn() << endl;
    cout << "b2 available: " << (b2.isAvailable() ? "Yes" : "No") << endl;

    cout << "\n[ISBN Validation]" << endl;
    cout << "9780321714114 valid? " << (Book::isValidIsbn("9780321714114") ? "Yes" : "No") << endl;
    cout << "12345 valid? " << (Book::isValidIsbn("12345") ? "Yes" : "No") << endl;
    cout << "0306406152 valid? " << (Book::isValidIsbn("0306406152") ? "Yes" : "No") << endl;
    cout << "030640615X valid? " << (Book::isValidIsbn("030640615X") ? "Yes" : "No") << endl;

    return 0;
}