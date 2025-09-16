#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

class Person {
public:
    Person(const std::string& name, int age);
    ~Person();
    void show() const;

    // 2025-09-14 深拷贝
    Person(const Person& other);
    Person& operator=(const Person& other);

    // 2025-09-14 异常+getter/setter
    void setAge(int age);
    void setName(const std::string& name);
    int  getAge() const;
    std::string getName() const;

    // 2025-09-16 模板函数 + 文件IO
    template<typename T>
    void writeToFile(const std::string& fname, const T& data) const;  // 模板函数
    void saveToFile(const std::string& fname) const;                // 保存对象
    static Person loadFromFile(const std::string& fname);           // 静态工厂
private:
    std::string m_name;
    int m_age;
};

/* ========== 模板实现必须放头文件 ========== */
template<typename T>
void Person::writeToFile(const std::string& fname, const T& data) const {
    std::ofstream ofs(fname, std::ios::app);
    if (!ofs) throw std::runtime_error("Cannot open file");
    ofs << data << '\n';
}