#include <iostream>

int main() {
    int z, n;
    std::cin >> z >> n;
    int *p1 = &z, *p2 = &n;
    *p1 += *p2;
    //std::cout << *p1; //idk how to do it using p2 so i hope there's a typo in the task :( 
    p2 = &z;
    std::cout << *p2;
    return 0;
}