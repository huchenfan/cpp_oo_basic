#pragma once
#include <iostream>
#include <string>

class Person {
public:
    Person(const std::string& name, int age);   // 构造函数
    ~Person();                             // 析构函数
    void show() const;                        // 显示信息
    std::string getName() const;                  // 获取姓名
    int getAge() const;                       // 获取年龄
    void setName(const std::string& name);       // 设置姓名
    void setAge(int age);                      // 设置年龄
private:
    std::string m_name;
    int m_age;
};
