#include "Library.h"
#include "Student.h"
#include <iostream>
using namespace std;

int main() {
    Library lib("SWUST Library");
    lib.addBook(Book("C++ Primer", "9780321714114", "Addison-Wesley", 128.0, 976, true));
    lib.addBook(Book("Data Structures", "9787040561234", "Higher Education Press", 45.5, 320, true));
    lib.addBook(Book("Introduction to Algorithms", "9780262033848", "MIT Press", 200.0, 1312, true));
    lib.displayAll();

    Student stu("25220960", "Zhou Yu", "CS", 3);
    stu.display();

    cout << "\n[Borrow Test]" << endl;
    Book* b1 = lib.findBook("9780321714114");
    Book* b2 = lib.findBook("9787040561234");
    stu.borrowBook(b1);
    stu.borrowBook(b2);
    stu.borrowBook(b2);

    cout << "\n[Student Status]" << endl;
    stu.display();

    cout << "\n[Book Status After Borrowing]" << endl;
    b1->display();
    b2->display();

    cout << "\n[Return Test]" << endl;
    stu.returnBook(b1);
    stu.display();
    b1->display();

    system("pause");
    return 0;
}
// 实验二：组合与依赖关系完成
