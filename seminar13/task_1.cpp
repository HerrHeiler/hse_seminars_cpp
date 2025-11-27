#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <functional>
using namespace std; // BAD
// 1) Create a triangle structure (a, b, c) with a constructor, output method, and area method.
// 2) Create a vector of 20 objects (any values).
// For each, output the area and find the triangle with the largest area.
// 3) Create a vector (push_back) of 1000 triangle values ​​by pointers and references.
//
using namespace chrono;

struct Triangle {
    int a, b, c;
    vector<int> dummy;
    Triangle(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c), dummy(100000) {}
    void print() const {
        cout << a << ' ' << b << ' ' << c << '\n';
    }
    double square() const {
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};
// Compare passing to methods.
// 1) passing by value
// 2) by reference
// 3) by pointer
// Do this 10,000 times and print the time
void pass_by_value(Triangle t) {}
void pass_by_ref(Triangle& t) {}
void pass_by_p(Triangle* t) {}

int main() {
    vector<Triangle> trs;
    for (int i = 1; i <= 20; ++i) trs.emplace_back(i, i + 1, i + 2);
    double max_area = 0;
    int max_idx = 0;
    for (int i = 0; i < (int)trs.size(); ++i) {
        double area = trs[i].square();
        cout << "Triangle " << i << " area: " << area << '\n';
        if (area > max_area) {
            max_area = area;
            max_idx = i;
        }
    }
    cout << "Largest triangle index: " << max_idx << " with area: " << max_area << "\n";
    vector<Triangle*> trs_pt;
    vector<reference_wrapper<Triangle>> triangle_refs_sim;
    for (int i = 0; i < 1000; ++i) {
        Triangle* ptr = new Triangle(i, i + 1, i + 2);
        trs_pt.push_back(ptr);
        triangle_refs_sim.push_back(*ptr);
    }
    Triangle sample(3, 4, 5);
    auto start = high_resolution_clock::now();
    for (int i = 0; i < 10000; ++i) {
        pass_by_value(sample);
    }
    auto end = high_resolution_clock::now();
    cout << "Pass by value time: " << duration_cast<microseconds>(end - start).count() << '\n';

    start = high_resolution_clock::now();
    for (int i = 0; i < 10000; ++i) {
        pass_by_ref(sample);
    }
    end = high_resolution_clock::now();
    cout << "Pass by reference time: " << duration_cast<microseconds>(end - start).count() << '\n';

    start = high_resolution_clock::now();
    for (int i = 0; i < 10000; ++i) {
        pass_by_p(&sample);
    }
    end = high_resolution_clock::now();
    cout << "Pass by pointer time: " << duration_cast<microseconds>(end - start).count() << '\n';
    for (auto ptr : trs_pt) {
        delete ptr;
    }
    return 0;
}
