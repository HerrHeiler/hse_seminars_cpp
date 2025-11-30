#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    long long x;
    long long y;

    long long dist() const {return x*x + y*y;}

    auto operator<=>(const Point& other) const {
        return dist() <=> other.dist();
    }
};



int main() {
    int a;
    std::cin >> a;
    std::vector<Point> points(a);
    for (int i = 0; i < a; ++i) std::cin >> points[i].x >> points[i].y;
    std::sort(points.begin(), points.end());
    for (const auto& e : points) std::cout << e.x << ' ' << e.y << std::endl;
    return 0;
}