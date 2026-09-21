#include "Book.h"
#include <iostream>
using namespace std;

int main() {
    Book b1;
    cout << "【默认构造函数创建的图书】" << endl;
    b1.display();


    Book b2("C++ Primer", "9780321714114", "Addison-Wesley", 128.0, 976, true);
    cout << "\n【重载构造函数创建的图书（合法 ISBN）】" << endl;
    b2.display();


    Book b3("非法ISBN测试", "12345", "测试出版社", 50.0, 200, true);
    cout << "\n【非法 ISBN 测试】" << endl;
    b3.display();


    cout << "\n【修改操作测试】" << endl;
    b3.setTitle("数据结构与算法");
    b3.setPublisher("高等教育出版社");
    b3.setPrice(45.5);
    b3.setPages(320);
    b3.setAvailable(false);
    b3.setIsbn("9787040561234");  
    b3.display();


    cout << "\n【获取操作测试】" << endl;
    cout << "b2 的书名: " << b2.getTitle() << endl;
    cout << "b2 的 ISBN: " << b2.getIsbn() << endl;
    cout << "b2 是否可借: " << (b2.isAvailable() ? "是" : "否") << endl;


    cout << "\n【ISBN 合法性验证】" << endl;
    cout << "9780321714114 合法? " << (Book::isValidIsbn("9780321714114") ? "是" : "否") << endl;
    cout << "12345 合法? " << (Book::isValidIsbn("12345") ? "是" : "否") << endl;
    cout << "0306406152 合法? " << (Book::isValidIsbn("0306406152") ? "是" : "否") << endl;
    cout << "030640615X 合法? " << (Book::isValidIsbn("030640615X") ? "是" : "否") << endl;

    return 0;
}
