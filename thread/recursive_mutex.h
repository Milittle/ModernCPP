//
// Created by milittle on 2022/3/21.
//

#ifndef MODERNTEST_RECURSIVE_MUTEX_H
#define MODERNTEST_RECURSIVE_MUTEX_H

#include <iostream>
#include <thread>
#include <mutex>

class X {
    std::recursive_mutex m;
    std::recursive_timed_mutex mm;
    std::string shared;
public:
    void fun1() {
        std::scoped_lock<std::recursive_mutex, std::recursive_timed_mutex> lk(m, mm);
        shared = "fun1";
        std::cout << "in fun1, shared variable is now " << shared << '\n';
    }
    void fun2() {
        std::lock_guard<std::recursive_mutex> lk(m);
        shared = "fun2";
        std::cout << "in fun2, shared variable is now " << shared << '\n';
        fun1(); // 递归锁在此处变得有用
        std::cout << "back in fun2, shared variable is " << shared << '\n';
    };
};

class XT {
    std::recursive_timed_mutex m;
    std::string shared;
public:
    void fun1() {
        std::lock_guard<std::recursive_timed_mutex> lk(m);
        shared = "fun1";
        std::cout << "in fun1, shared variable is now " << shared << '\n';
    }
    void fun2() {
        std::lock_guard<std::recursive_timed_mutex> lk(m);
        shared = "fun2";
        std::cout << "in fun2, shared variable is now " << shared << '\n';
        fun1(); // 递归锁在此处变得有用
        std::cout << "back in fun2, shared variable is " << shared << '\n';
    };
};

int recursive_lock_test()
{
    X x;
    std::thread t1(&X::fun1, &x);
    std::thread t2(&X::fun2, &x);
    t1.join();
    t2.join();
}

#endif //MODERNTEST_RECURSIVE_MUTEX_H
