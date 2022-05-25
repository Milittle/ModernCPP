//
// Created by milittle on 2022/5/25.
//

#include <iostream>

template<typename T>
T adder(T v) {
    std::cout << __PRETTY_FUNCTION__ << "\n";
    return v;
}

template<typename T, typename... Args>
T adder(T v, Args... args) {
    std::cout << __PRETTY_FUNCTION__ << "\n";
    return v + adder(args...);
}

void test_01() {
    std::cout << __PRETTY_FUNCTION__ << "\n";
    int sum = adder(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    std::cout << sum << std::endl;
}

template<typename T>
bool pair_comparer(T a) {
    return false;
}

template<typename T>
bool pair_comparer(T a, T b) {
    // In real-world code, we wouldn't compare floating point values like
    // this. It would make sense to specialize this function for floating
    // point types to use approximate comparison.
    std::cout << __PRETTY_FUNCTION__ << "\n";
    return a == b;
}

template<typename T, typename... Args>
bool pair_comparer(T a, T b, Args... args) {
    std::cout << __PRETTY_FUNCTION__ << "\n";
    return a == b && pair_comparer(args...);
}

void test_02() {
    bool sign = pair_comparer(1.5, 1.5, 2, 2, 6, 6);
    std::cout << "We get compare result test02: " << sign << std::endl;
}

void test_03() {
    bool s = pair_comparer(1.5, 1.5, 2, 2, 6, 6, 7);
    std::cout << "We get compare result test03:" << s << std::endl;
}

int main() {
    test_01();
    test_02();
    test_03();
}