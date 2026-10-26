#ifndef TEACHER_H
#define TEACHER_H

#include "User.h"

// 教师类，继承自 User
class Teacher : public User {
private:
    string title;   // 职称，如教授、副教授

public:
    Teacher();
    Teacher(const string& id, const string& name, const string& department,
            int maxBorrow, const string& title);

    void setTitle(const string& title);
    string getTitle() const;

    void display() const override;
};

#endif