#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include <iostream>
using namespace std;

// 类模板：可以管理任意类型 T 的数据
template <typename T>
class Repository {
private:
    vector<T> items;   // 底层使用 vector 容器

public:
    // 增加数据
    void add(const T& item) {
        items.push_back(item);
    }

    // 删除指定索引的数据
    void remove(int index) {
        if (index >= 0 && index < items.size()) {
            items.erase(items.begin() + index);
        }
    }

    // 获取大小
    int size() const {
        return items.size();
    }

    // 获取指定索引的数据
    T& get(int index) {
        return items[index];
    }

    // 获取底层的 vector 用于遍历
    const vector<T>& getAll() const {
        return items;
    }

    // 清空
    void clear() {
        items.clear();
    }
};

#endif