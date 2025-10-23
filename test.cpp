#include <iostream>
#include <fstream>

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    std::fstream file("data.txt", std::ios::in | std::ios::out);
    //std::ifstream fin;
    //Fin.open("input.txt")
    return 0;
}