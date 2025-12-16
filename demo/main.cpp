#include <iostream>
#include <vector>

class BaseNumber {
public:
    virtual ~BaseNumber() = default;
    virtual void print() const;
    virtual int getValue() const;
};

class Number : BaseNumber {
    int value;
public:
    Number(int v) : value(v) {};

    int getValue() const override {
        return value;
    }
    void setValue(int v) {
        value = v;
    }
    void print() const override {
        std::cout << "Number: " << value << std::endl;
    }
};

class NumberCollection {
    std::vector<Number> data;
public:
    void add(int v) {
        Number n(v);
        data.push_back(n);
    }
    void printAll() {
        for (auto& e : data) {
            e.print();
        }
    }
};



int main() {

    std::cout << "running tests on 1 task" << std::endl;
    Number n1(2);
    n1.print();
    n1.setValue(5);
    n1.print();

    std::cout << "running tests on 2 task" << std::endl;
    NumberCollection nc;
    nc.add(1);
    nc.printAll();
    nc.add(2);
    nc.add(3);
    nc.printAll();

    std::cout << "running tests on 3 task" << std::endl;
    Number n2(2);
    n2.print();
    return 0;
}