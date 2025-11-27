#include <iostream>
#include <vector>
#include <fstream>

/*Implement  the “Time” structure with three fields: hours, minutes
and seconds. Define a subtraction operation such that
the result is an object of type time containing
how much time is between the first and second event. If
the second event is later than the first, the answer should be equal to
zero, otherwise return a time structure containing the difference
between these events (hours, minutes, seconds).*/

struct Time {
    int hours;
    int minutes;
    int seconds;
    Time(int hours, int minutes, int seconds) {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }
    Time operator-(const Time& t) const {
        return this->substraction(t);
    }
    Time substraction(const Time &t) const {
        int sec1 = t.hours * 3600 + t.minutes * 60 + t.seconds;
        int sec2 = this->hours * 3600 + this->minutes * 60 + this->seconds;
        int res = sec2 - sec1;
        if (res < 0)
            return Time(0, 0, 0);
        return Time(res / 3600,(res % 3600) / 60, res % 60);
    }
    
};

std::ostream& operator<<(std::ostream& out, const Time& y) {
    return out << y.hours << ' ' << y.minutes << ' ' << y.seconds << '\n';
}

int main() {
    Time t1 = Time(10, 50, 50);
    Time t2 = Time(9, 30, 30);
    Time t3 = t1 - t2;
    std::cout << t3; 
    return 0;
}

















//
//
// struct Time {
//     int hours;
//     int minutes;
//     int seconds;
//     Time(int hours, int minutes, int seconds) {
//         this->hours = hours;
//         this->minutes = minutes;
//         this->seconds = seconds;  }
//     Time operator-(const Time& t) const {
//         return this->substraction(t);
//     }
//     friend std::ostream& operator<<(std::ostream& out, const Time& o);
//     Time substraction(const Time &t) const {
//         int sec1 = t.hours * 3600 + t.minutes * 60 + t.seconds;
//         int sec2 = this->hours * 3600 + this->minutes * 60 + this->seconds;
//         int res = sec2 - sec1;
//         if (res < 0)
//             return Time(0, 0, 0);
//         return Time(res / 3600,(res % 3600) / 60, res % 60); } };
// std::ostream& operator<<(std::ostream& out, const Time& y)
// {
//     return out << y.hours << ' ' << y.minutes << ' ' << y.seconds << '\n'; // can access private member Y::data
// }
// int main() {
//     Time t1 = Time(10, 50, 50);
//     Time t2 = Time(9, 30, 30);
//     Time t3 = t1 - t2;
//     std::ofstream out("example1.txt");
//     std::cout << t3; // оператор вывода
//     out << t1;
//     out << t2;
//     out << t3;
//     out.close();
//     return 0;
// }
//
