#include <iostream>
// Task 02.

// Implement  the “Time” structure with three fields: hours, minutes
// and seconds. Define a subtraction operation such that
// the result is an object of type time containing
// how much time is between the first and second event. If
// the second event is later than the first, the answer should be equal to
// zero, otherwise return a time structure containing the difference
// between these events (hours, minutes, seconds).
struct Time {
    int seconds;
    int minutes;
    int hours;
    Time substraction(Time event1, Time event2) const {
        Time result;
        int res = event2.seconds + event2.minutes*60 + event2.hours*60*60 - (event1.seconds + event1.minutes*60 + event1.hours*60*60);
        if (res <= 0) return result;
        result.hours = res/3600;
        res -= result.hours*3600;
        result.minutes = res/60;
        res -= result.minutes*60;
        result.seconds = res;
        return result;
    }
};

int main() {
    Time e1, e2, dif;
    e1.hours = 10;
    e1.minutes = 5;
    e1.seconds = 16;
    e2.hours = 10;
    e2.minutes = 5;
    e2.seconds = 10;
    dif = e1.substraction(e1, e2);
    std::cout << dif.seconds << ' ' << dif.hours;
    return 0;
}