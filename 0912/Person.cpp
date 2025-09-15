#include "Person.h"

// 构造函数
Person::Person(const std::string& name, int age)
        : m_name(name), m_age(age) {
    std::cout << "Person(" << m_name << "," << m_age << ") created\n";
}

// 拷贝构造函数
Person::Person(const Person& other)
        : m_name(other.m_name), m_age(other.m_age) {
    std::cout << "Person COPY(" << m_name << "," << m_age << ")\n";
}

// 析构函数
Person::~Person() {
    std::cout << "Person(" << m_name << "," << m_age << ") destroyed\n";
}

// 赋值运算符重载
Person& Person::operator=(const Person& other) {
    if (this != &other) { m_name = other.m_name; m_age = other.m_age; }  // 避免自己与自己赋值， 浪费系统资源
    return *this;
}

void Person::show() const {
    std::cout << m_name << " " << m_age << '\n';
}

void Person::setAge(int age) {
    if (age < 0) throw std::invalid_argument("Age must be >= 0");
    m_age = age;
}
void Person::setName(const std::string& name) { m_name = name; }
int  Person::getAge() const { return m_age; }
std::string Person::getName() const { return m_name; }