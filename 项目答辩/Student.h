#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"

// 学生类，继承自 User
class Student : public User {
private:
    string major;   // 专业

public:
    Student();
    Student(const string& id, const string& name, const string& department,
            int maxBorrow, const string& major);

    void setMajor(const string& major);
    string getMajor() const;

    void display() const override;
};

#endif