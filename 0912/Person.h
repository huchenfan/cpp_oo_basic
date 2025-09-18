#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <chrono>
#include <unordered_map>

class Person {
public:
    Person(const std::string& name, int age);
    ~Person();
    void show() const;

    // 深拷贝
    Person(const Person& other);
    Person& operator=(const Person& other);

    // 异常+getter/setter
    void setAge(int age);
    void setName(const std::string& name);
    int  getAge() const;
    std::string getName() const;

    // 文件IO
    void saveToFile(const std::string& fname) const;
    static Person loadFromFile(const std::string& fname);

    // 2025-09-18 性能计时 + 缓存
    template<typename Func>
    static double measure(Func&& f);                      // 毫秒计时
    static void dumpCache();                              // 打印缓存
private:
    std::string m_name;
    int m_age;
    static std::unordered_map<std::string, int> s_cache;  // 简单缓存
};

/* ========== 模板实现放头文件（性能计时） ========== */
template<typename Func>
double Person::measure(Func&& f) {
    auto t0 = std::chrono::high_resolution_clock::now();
    f();
    auto t1 = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(t1 - t0).count();
}
