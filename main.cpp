#include <iostream>
#include "meta/meta.h"

template<typename T>
typename std::enable_if<my_is_integral_v<T>, int>::type
up(T t){
    t += 1;
    return t;
}

int main() {
    std::cout << up(123) << std::endl;
    return 0;
}
