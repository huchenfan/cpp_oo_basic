#include <iostream>
#include <string>
#include <stdexcept>      // 2025-09-14 异常

class Person {
public:
    Person(const std::string& name, int age);
    ~Person();
    void show() const;

    // 2025-09-14 新增：深拷贝 + 异常 + getter/setter
    Person(const Person& other);                    // 拷贝构造
    Person& operator=(const Person& other);         // 赋值运算符
    void setAge(int age);                           // 带异常
    void setName(const std::string& name);
    int  getAge() const;
    std::string getName() const;
private:
    std::string m_name;
    int m_age;
};

