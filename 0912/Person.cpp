#include "Person.h"

Person::Person(const std::string& name, int age)
        : m_name(name), m_age(age) {
    std::cout << "Person(" << m_name << "," << m_age << ") created\n";
}

Person::~Person() {
    std::cout << "Person(" << m_name << "," << m_age << ") destroyed\n";
}

void Person::show() const {
    std::cout << m_name << " " << m_age << '\n';
}
