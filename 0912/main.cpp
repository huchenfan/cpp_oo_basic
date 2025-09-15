#include "Person.h"

int main() {
    try {
        Person p1("Tom", 18);
        p1.show();                                    // 09-12 基础

        Person p2 = p1;                               // 09-14 深拷贝
        p2.setName("Jerry");
        p2.setAge(20);
        std::cout << "p1: " << p1.getName() << " " << p1.getAge() << '\n';
        std::cout << "p2: " << p2.getName() << " " << p2.getAge() << '\n';

        p1.setAge(-5);                                // 09-14 异常测试
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << '\n';
    }

    return 0;
}

