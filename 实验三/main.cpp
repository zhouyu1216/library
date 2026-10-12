#include "Library.h"
#include "GeneralBook.h"
#include "Magazine.h"
#include "EBook.h"
#include "Student.h"
#include "Teacher.h"
#include <iostream>
using namespace std;

int main() {
    Library lib("SWUST Library");

    // 1. 添加不同类型的图书（用 new 动态创建子类对象）
    lib.addBook(new GeneralBook("C++ Primer", "9780321714114", "Addison-Wesley",
                                128.0, 976, true, "Lippman", "Programming"));
    lib.addBook(new Magazine("National Geographic", "9781234567890", "NatGeo",
                             35.0, 120, true, 202, "October"));
    lib.addBook(new EBook("Effective C++", "9780321334879", "Addison-Wesley",
                          50.0, 320, true, 5.5, "PDF"));

    // 2. 显示所有图书（多态调用 display）
    lib.displayAllBooks();

    // 3. 添加不同类型的用户
    lib.addUser(new Student("25220960", "Zhou Yu", "CS", 5, "Computer Science"));
    lib.addUser(new Teacher("T001", "Prof. Li", "CS", 10, "Professor"));

    // 4. 显示所有用户
    lib.displayAllUsers();

    // 5. 借书测试（依赖关系 + 多态）
    cout << "\n[Borrow Test]" << endl;
    User* stu = lib.findUser("25220960");
    Book* b1 = lib.findBook("9780321714114");
    Book* b2 = lib.findBook("9781234567890");
    Book* b3 = lib.findBook("9780321334879");

    stu->borrowBook(b1);
    stu->borrowBook(b2);
    stu->borrowBook(b3);
    stu->borrowBook(b1);   // 重复借，应失败

    // 6. 显示学生状态
    cout << "\n[Student Status]" << endl;
    stu->display();

    // 7. 显示借出后图书状态
    cout << "\n[Book Status After Borrowing]" << endl;
    lib.displayAllBooks();

    // 8. 还书测试
    cout << "\n[Return Test]" << endl;
    stu->returnBook(b1);
    stu->display();

    return 0;
}