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

std::string Person::getName() const {
    return m_name;
}

int Person::getAge() const {
    return m_age;
}

void Person::setName(const std::string& name) {
    m_name = name;
}

void Person::setAge(int age) {
    m_age = age;
}