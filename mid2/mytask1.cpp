#include <iostream>
#include <vector>

class Student {
    std::string name;
    int grade;
public:
    Student(std::string n, int g) : name(n), grade(g) {};
    int getGrade() const {
        return grade;
    }
    std::string getName() const {
        return name;
    }
    void setGrade(int g) {
        grade = g;
    }
    void print() const {
        std::cout << "Student: " << name << ", Grade: " << grade;
    }
    friend std::ostream& operator<<(std::ostream& os, const Student& s);
};

std::ostream& operator<<(std::ostream& os, const Student& s) {
    os <<  "Student: " << s.name << ", Grade: " << s.grade;
    return os;
}

int main() {
    Student s1("Alice", 100);
    s1.setGrade(85);
    std::cout << s1;
    return 0;
}