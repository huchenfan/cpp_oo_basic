#include "Person.h"

int main() {
    Person p("Tom", 18);
    p.show();             // 调用 show 方法

    std::cout << "Name: " << p.getName() << ", Age: " << p.getAge() << '\n';

    p.setName("Jerry");
    p.setAge(20);

    std::cout << "After changes - Name: " << p.getName() << ", Age: " << p.getAge() << '\n';
    p.show();             // 再次调用 show 方法

    return 0;
}