#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Date {
    int day;
    int month;
    int year;

    auto operator<=>(const Date& other) const {
        return std::tie(year, month, day) <=> std::tie(other.year, other.month, other.day);
    }
};

struct Student {
    std::string name;
    std::string last_name;
    Date date;
};

bool date_sort(const Student& first, const Student& second) {
    if (first.date < second.date) return true;
    if (first.date > second.date) return false;
    if (first.last_name < second.last_name) return true;
    if (first.last_name > second.last_name) return false;
    return (first.name > second.name);
}

bool name_sort(const Student& first, const Student& second) {
    if (first.last_name < second.last_name) return true;
    if (first.last_name > second.last_name) return false;
    if (first.name < second.name) return true;
    if (first.name > second.name) return false;
    return (first.date > second.date);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        Student t;
        std::cin >> t.name >> t.last_name >> t.date.day >> t.date.month >> t.date.year;
        students.push_back(t);
    }
    std::string ssort;
    std::cin >> ssort;
    if (ssort == "name") {
        std::sort(students.begin(), students.end(), name_sort);
    } else {
        std::sort(students.begin(), students.end(), date_sort);
    }
    for (const auto& e : students) {
        if (e.date.day != 0) std::cout << e.name << ' ' << e.last_name << ' ' << e.date.day << '.' << e.date.month << '.' << e.date.year << std::endl;
    }
    return 0;
}