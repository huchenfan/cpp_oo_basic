#include "Person.h"
#include <iostream>

int main() {
    try {
        Person p("Alice", 25);
        p.saveToFile("person.txt");                      // 保存对象
        p.writeToFile("log.txt", "Hello Template!");     // 模板函数

        Person p2 = Person::loadFromFile("person.txt");  // 工厂加载
        std::cout << "Loaded: " << p2.getName() << " " << p2.getAge() << '\n';
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << '\n';
    }
    return 0;
}