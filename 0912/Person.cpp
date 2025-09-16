#include "Person.h"

/* ---------- 2025-09-12 基础 ---------- */
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

/* ---------- 2025-09-14 深拷贝 ---------- */
Person::Person(const Person& other)
        : m_name(other.m_name), m_age(other.m_age) {
    std::cout << "Person COPY(" << m_name << "," << m_age << ")\n";
}
Person& Person::operator=(const Person& other) {
    if (this != &other) { m_name = other.m_name; m_age = other.m_age; }
    return *this;
}

/* ---------- 2025-09-14 异常+getter/setter ---------- */
void Person::setAge(int age) {
    if (age < 0) throw std::invalid_argument("Age must be >= 0");
    m_age = age;
}
void Person::setName(const std::string& name) { m_name = name; }
int  Person::getAge() const { return m_age; }
std::string Person::getName() const { return m_name; }

/* ---------- 2025-09-16 模板函数 + 文件IO ---------- */

void Person::saveToFile(const std::string& fname) const {
    std::ofstream ofs(fname);
    if (!ofs) throw std::runtime_error("Cannot open file");
    ofs << m_name << '\n' << m_age << '\n';
}

Person Person::loadFromFile(const std::string& fname) {
    std::ifstream ifs(fname);
    if (!ifs) throw std::runtime_error("Cannot open file");
    std::string name; int age;
    std::getline(ifs, name); ifs >> age;
    return Person(name, age);
}