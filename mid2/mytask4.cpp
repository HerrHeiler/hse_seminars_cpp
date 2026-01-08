#include <iostream>
#include <vector>
#include <string>

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

class GraduateStudent : public Person{
    std::string name;
    int weighted;
public:
    GraduateStudent(std::string _name, int _grade, int _thesisScore) : name(_name), weighted(_grade*0.7+_thesisScore*0.3) {};
    int getGrade() const override {
        return weighted;
    }
    void print() const override {
        std::cout << "Graduate: " << name << " (weighted: " << weighted << ')';
    }
};

class TeachingAssistant : public Person {
    std::string name;
    int bonus;
public:
    TeachingAssistant(std::string _name, int _grade, int _hours) : name(_name), bonus(_grade + _hours*2) {};
    int getGrade() const override {
        return bonus;
    }
    void print() const override {
        std::cout << "TA: " << name << " (bonus: " << bonus << ')';
    }
};

class StudentCollection {
    std::vector<Person*> data;
public:
    void add(Person* p) {
        data.push_back(p);
    }
    void printAll() {
        for (auto& e : data) {
            e->print();
            std::cout << std::endl;
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const StudentCollection& sc);
    StudentCollection() = default;
    StudentCollection(int _cap) : data(_cap) {};
    ~StudentCollection() {
        for (auto& e : data) {
            delete e;
        }
    }
};

std::ostream& operator<<(std::ostream& os, const StudentCollection& sc) {
    for (auto& e : sc.data) {
            os << e << std::endl;
        }
    return os;
}

int main() {
    Person* p1 = new Student("3", 80);
    Person* p2 = new GraduateStudent("Eve", 85, 90);
    Person* p3 = new TeachingAssistant("Frank", 78, 4);
    StudentCollection sc;
    sc.add(new Student("3", 80));
    sc.add(new GraduateStudent("Eve", 85, 90));
    sc.add(new TeachingAssistant("Frank", 78, 4));
    sc.printAll();
    return 0;
}