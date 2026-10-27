#include "Library.h"
#include "GeneralBook.h"
#include "Magazine.h"
#include "EBook.h"
#include "Student.h"
#include "Teacher.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include <cstdlib>  // 用于 system()
using namespace std;

// 清空输入缓存的辅助函数
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void displayMenu() {
    cout << "\n========================================" << endl;
    cout << "    欢迎使用西南科技大学图书馆管理系统" << endl;
    cout << "========================================" << endl;
    cout << "  1. 查看所有图书资源" << endl;
    cout << "  2. 添加新图书资源" << endl;
    cout << "  3. 查看所有借阅人" << endl;
    cout << "  4. 添加新借阅人" << endl;
    cout << "  5. 借阅图书" << endl;
    cout << "  6. 归还图书" << endl;
    cout << "  0. 保存数据并安全退出" << endl;
    cout << "========================================" << endl;
    cout << "请输入选项(0-6): ";
}

int main() {
    // 解决 Windows 终端中文乱码
    system("chcp 65001 > nul");

    Library lib("SWUST Library");
    string dataFile = "library_data.txt";
    
    // 启动时加载数据
    lib.loadFromFile(dataFile);
    
    // 如果是第一次运行，生成一点初始数据
    if (lib.getBookCount() == 0) {
        lib.addBook(new GeneralBook("C++Primer", "9780321714114", "Addison-Wesley", 128.0, 976, true, "Lippman", "CS"));
        lib.addBook(new Magazine("NationalGeographic", "9781234567890", "NatGeo", 35.0, 120, true, 202, "Oct"));
        lib.addBook(new EBook("EffectiveC++", "9780321334879", "Addison-Wesley", 50.0, 320, true, 5.5, "PDF"));
        
        lib.addUser(new Student("25220001", "张三", "计科2506", 5, "计算机科学"));
        lib.addUser(new Teacher("T001", "李教授", "计科", 10, "Professor"));
    }

    int choice;
    while (true) {
        displayMenu();
        if (!(cin >> choice)) {
            cout << "输入无效，请输入数字！" << endl;
            clearInput();
            continue;
        }

        if (choice == 0) {
            lib.saveToFile(dataFile);
            cout << "感谢使用，再见！" << endl;
            break;
        }

        switch (choice) {
            case 1: {
                lib.displayAllBooks();
                break;
            }
            case 2: {
                int type;
                cout << "请选择图书类型 (1.普通图书 2.杂志 3.电子书): ";
                cin >> type;
                string title, isbn, pub;
                double price;
                int pages;
                cout << "输入书名(无空格): "; cin >> title;
                cout << "输入ISBN: "; cin >> isbn;
                cout << "输入出版社(无空格): "; cin >> pub;
                cout << "输入价格: "; cin >> price;
                cout << "输入页数: "; cin >> pages;

                if (type == 1) {
                    string author, category;
                    cout << "输入作者(无空格): "; cin >> author;
                    cout << "输入分类(无空格): "; cin >> category;
                    lib.addBook(new GeneralBook(title, isbn, pub, price, pages, true, author, category));
                } else if (type == 2) {
                    int issue;
                    string month;
                    cout << "输入期号: "; cin >> issue;
                    cout << "输入月份: "; cin >> month;
                    lib.addBook(new Magazine(title, isbn, pub, price, pages, true, issue, month));
                } else if (type == 3) {
                    double size;
                    string format;
                    cout << "输入文件大小(MB): "; cin >> size;
                    cout << "输入格式(如PDF): "; cin >> format;
                    lib.addBook(new EBook(title, isbn, pub, price, pages, true, size, format));
                }
                break;
            }
            case 3: {
                lib.displayAllUsers();
                break;
            }
            case 4: {
                int type;
                cout << "请选择用户类型 (1.学生 2.教师): ";
                cin >> type;
                string id, name, dept;
                int maxB;
                cout << "输入学号/工号: "; cin >> id;
                cout << "输入姓名(无空格): "; cin >> name;
                cout << "输入院系(无空格): "; cin >> dept;
                cout << "输入最大借阅量: "; cin >> maxB;

                if (type == 1) {
                    string major;
                    cout << "输入专业(无空格): "; cin >> major;
                    lib.addUser(new Student(id, name, dept, maxB, major));
                } else if (type == 2) {
                    string title;
                    cout << "输入职称(无空格): "; cin >> title;
                    lib.addUser(new Teacher(id, name, dept, maxB, title));
                }
                break;
            }
            case 5: {
                string id, isbn;
                cout << "请输入您的学号/工号: "; cin >> id;
                cout << "请输入要借阅的图书ISBN: "; cin >> isbn;
                
                User* u = lib.findUser(id);
                Book* b = lib.findBook(isbn);
                
                if (u && b) {
                    u->borrowBook(b);
                } else {
                    cout << "[错误] 用户或图书不存在！" << endl;
                }
                break;
            }
            case 6: {
                string id, isbn;
                cout << "请输入您的学号/工号: "; cin >> id;
                cout << "请输入要归还的图书ISBN: "; cin >> isbn;
                
                User* u = lib.findUser(id);
                Book* b = lib.findBook(isbn);
                
                if (u && b) {
                    u->returnBook(b);
                } else {
                    cout << "[错误] 用户或图书不存在！" << endl;
                }
                break;
            }
            default:
                cout << "无效选项，请重新输入！" << endl;
        }
    }

    return 0;
}