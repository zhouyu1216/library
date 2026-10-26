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
    string dataFile = "library_data.txt";

    // ==========================================
    // 1. 模拟程序启动：从文件加载数据
    // ==========================================
    lib.loadFromFile(dataFile);

    // 如果是第一次运行（没有文件），就添加初始数据
    if (lib.getBookCount() == 0) {
        cout << "\n[Init] Adding initial books..." << endl;
        lib.addBook(new GeneralBook("C++Primer", "9780321714114", "Addison-Wesley", 128.0, 976, true, "Lippman", "Programming"));
        lib.addBook(new Magazine("NationalGeographic", "9781234567890", "NatGeo", 35.0, 120, true, 202, "October"));
        lib.addBook(new EBook("EffectiveC++", "9780321334879", "Addison-Wesley", 50.0, 320, true, 5.5, "PDF"));
    }

    // 显示当前所有图书
    lib.displayAllBooks();

    // ==========================================
    // 2. 模拟用户操作：把第一本书借走
    // ==========================================
    cout << "\n[Action] Borrowing the first book..." << endl;
    Book* b1 = lib.findBook("9780321714114");
    if (b1 != nullptr && b1->isAvailable()) {
        b1->borrow(); // 改变状态
        cout << "Book status changed to borrowed!" << endl;
    } else {
        cout << "Book is already borrowed or not found." << endl;
    }

    // ==========================================
    // 3. 模拟程序关闭：保存数据到文件
    // ==========================================
    lib.saveToFile(dataFile);

    return 0;
}