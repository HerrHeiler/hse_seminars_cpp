#include <iostream>
#include <vector>

class Person {
public:
    virtual void print() const = 0;
    virtual int getGrade() const = 0;
    virtual ~Person() = default;
};

class Student : public Person {
    std::string name;
    int grade;
public:
    Student() = default;
    Student(std::string n, int g) : name(n), grade(g) {};
    int getGrade() const override {
        return grade;
    }
    std::string getName() {
        return name;
    }
    void setGrade(int g) {
        grade = g;
    }
    void print() const override {
        std::cout << "Student: " << name << ", Grade: " << grade;
    }
    friend std::ostream& operator<<(std::ostream& os, const Student& s);
};

std::ostream& operator<<(std::ostream& os, const Student& s) {
    os <<  "Student: " << s.name << ", Grade: " << s.grade;
    return os;
}

int main() {
    Person* p = new Student("Bob", 92);
    p->print();
    return 0;
}