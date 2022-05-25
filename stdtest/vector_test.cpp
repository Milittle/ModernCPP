//
// Created by milittle on 2022/5/25.
//

#include <vector>
#include <iostream>

#include "../tools/output_container.h"

void test_01() {
    std::vector<int> vecs;
    vecs.reserve(100);
    std::cout << vecs.capacity() << std::endl;
    for (int i = 0; i < vecs.size(); ++i) {
        std::cout << vecs[i] << std::endl;
    }

    std::vector<int> b(vecs);
    b.push_back(100);

    for (const auto & a : b) {
        std::cout << "Single output: " << a << std::endl;
    }
    std::cout << "Container output: " << b << std::endl;
}

int main() {
    test_01();
}