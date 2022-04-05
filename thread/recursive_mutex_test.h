//
// Created by milittle on 2022/3/21.
//

#ifndef MODERNTEST_RECURSIVE_MUTEX_TEST_H
#define MODERNTEST_RECURSIVE_MUTEX_TEST_H

#include <iostream>
#include <thread>
#include <mutex>

class RecursiveMutexTest {
    std::recursive_mutex m;
    std::string shared;
public:
    void fun1() {
        std::scoped_lock<std::recursive_mutex> lk(m);
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

void recursive_mutex_test()
{
    RecursiveMutexTest x;
    std::thread t1(&RecursiveMutexTest::fun1, &x);
    std::thread t2(&RecursiveMutexTest::fun2, &x);
    t1.join();
    t2.join();
}

class RecursiveTimedMutexTest {
    std::recursive_timed_mutex m;
    std::string shared;
public:
    void fun1() {
        std::unique_lock<std::recursive_timed_mutex> lk(m, std::try_to_lock);
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

void recursive_timed_mutex_test()
{
    RecursiveTimedMutexTest x;
    std::thread t1(&RecursiveTimedMutexTest::fun1, &x);
    std::thread t2(&RecursiveTimedMutexTest::fun2, &x);
    t1.join();
    t2.join();
}

#endif //MODERNTEST_RECURSIVE_MUTEX_TEST_H
