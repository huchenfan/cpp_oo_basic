#pragma once
#include <iostream>
#include <string>

class Person {
public:
    Person(const std::string& name, int age);   // 构造
    ~Person();                                  // 析构
    void show() const;                          // 打印
private:
    std::string m_name;
    int m_age;
};

