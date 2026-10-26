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

    // 1. 添加不同类型的图书
    lib.addBook(new GeneralBook("C++ Primer", "9780321714114", "Addison-Wesley",
                                128.0, 976, true, "Lippman", "Programming"));
    lib.addBook(new Magazine("National Geographic", "9781234567890", "NatGeo",
                             35.0, 120, true, 202, "October"));
    lib.addBook(new EBook("Effective C++", "9780321334879", "Addison-Wesley",
                          50.0, 320, true, 5.5, "PDF"));

    // 2. 显示所有图书
    lib.displayAllBooks();

    // 3. 添加不同类型的用户
    lib.addUser(new Student("25220960", "Zhou Yu", "CS", 5, "Computer Science"));
    lib.addUser(new Teacher("T001", "Prof. Li", "CS", 10, "Professor"));

    // 4. 显示所有用户
    lib.displayAllUsers();

    // 5. 借书测试
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

    // ==========================================
    // 9. 实验四补充：多态性与虚析构函数测试
    // ==========================================
    cout << "\n[Polymorphism Test: Base Pointer -> Derived Object]" << endl;
    
    // 用基类指针指向不同的派生类对象
    Book* pBook1 = new GeneralBook("Clean Code", "9780132350884", "Prentice Hall", 60.0, 464, true, "Robert Martin", "Programming");
    Book* pBook2 = new EBook("Refactoring", "9780134757599", "Addison-Wesley", 70.0, 448, true, 8.2, "PDF");
    
    // 通过基类指针调用虚函数，体现多态
    pBook1->display();
    pBook2->display();

    // 测试虚析构函数（释放时会安全调用子类的析构）
    delete pBook1;
    delete pBook2;
    // ===== 实验五：模板泛型测试 =====
    cout << "\n[Template Test: Repository<int>]" << endl;
    Repository<int> intRepo;
    intRepo.add(100);
    intRepo.add(200);
    cout << "Int Repo Size: " << intRepo.size() << endl;
    cout << "First Item: " << intRepo.get(0) << endl;

    cout << "\n[Template Test: Repository<string>]" << endl;
    Repository<string> strRepo;
    strRepo.add("Hello");
    strRepo.add("Templates");
    for (auto s : strRepo.getAll()) {
        cout << "String Item: " << s << endl;
    }
    return 0;
}