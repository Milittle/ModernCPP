//
// Created by milittle on 2022/3/16.
//

#ifndef MODERNTEST_CALL_ONCE_H
#define MODERNTEST_CALL_ONCE_H

#endif //MODERNTEST_CALL_ONCE_H

#include <thread>
#include <mutex>
#include <iostream>

std::once_flag flag1, flag2;

void simple_do_once()
{
    std::call_once(flag1, [](){ std::cout << "Simple example: called once\n"; });
}

void may_throw_function(bool do_throw)
{
    if (do_throw) {
        std::cout << "throw: call_once will retry\n"; // 这会出现多于一次
        throw std::exception();
    }
    std::cout << "Didn't throw, call_once will not attempt again\n"; // 保证一次
}

//对于call_once必须是一次完成的调用，不然是不会结束once_flags的
void do_once(bool do_throw)
{
    try {
        std::call_once(flag2, may_throw_function, do_throw);
    }
    catch (...) {
    }
}


//test call once
void test_call_once()
{
    std::thread st1(simple_do_once);
    std::thread st2(simple_do_once);
    std::thread st3(simple_do_once);
    std::thread st4(simple_do_once);
    st1.join();
    st2.join();
    st3.join();
    st4.join();

    std::thread t1(do_once, true);
    std::thread t2(do_once, false);
    std::thread t3(do_once, true);
    std::thread t4(do_once, true);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}
