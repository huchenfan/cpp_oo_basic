#include "Person.h"
#include <iostream>

int main() {
    double t = Person::measure([]{
        Person p("Bob", 30);
        p.saveToFile("bob.txt");
        Person p2 = Person::loadFromFile("bob.txt");
    });
    std::cout << "IO+构造耗时: " << t << " ms\n";
    Person::dumpCache();   // 打印缓存
    return 0;
}