#include <iostream>
#include <vector>
#include <string>

class Student {
    std::string name;
    int grade;
public:
    Student() = default;
    Student(std::string n, int g) : name(n), grade(g) {};
    int getGrade() {
        return grade;
    }
    std::string getName() {
        return name;
    }
    void setGrade(int g) {
        grade = g;
    }
    void print() {
        std::cout << "Student: " << name << ", Grade: " << grade;
    }
    friend std::ostream& operator<<(std::ostream& os, const Student& s);
};

std::ostream& operator<<(std::ostream& os, const Student& s) {
    os <<  "Student: " << s.name << ", Grade: " << s.grade;
    return os;
}

class StudentCollection {
    std::vector<Student> students;
public:
    void add(std::string _name, int _grade) {
        Student s(_name, _grade);
        students.push_back(s);
    }
    void printAll() {
        for (auto& e : students) {
            e.print();
            std::cout << std::endl;
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const StudentCollection& sc);
    StudentCollection() = default;
    explicit StudentCollection(int _cap) {
        students.reserve(_cap);
    };
};

std::ostream& operator<<(std::ostream& os, const StudentCollection& sc) {
    for (const auto& e : sc.students) {
            os << e << std::endl;
        }
    return os;
}

int main() {
    StudentCollection sc1(4);
    StudentCollection sc2;
    sc2.add("ds", 45);
    sc2.add("drt", 65);
    sc2.add("rt", 95);
    sc2.add("ogi", 4);
    std::cout << sc2;
    return 0;
}