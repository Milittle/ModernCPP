//
// Created by milittle on 2022/3/22.
//

#ifndef MODERNTEST_MUTEX_TEST_H
#define MODERNTEST_MUTEX_TEST_H

#include <mutex>
#include <thread>
#include <vector>
#include <iostream>
#include <chrono>

class MutexTest {
    std::mutex mx;
    std::vector<int> shared_data{0};
public:
    void push_data(int i) {
        mx.unlock(); //这个没关系
        mx.lock();
        bool t = mx.try_lock();
        std::cout << "try lock sign: " << t << std::endl;
        //mx.lock(); 会阻塞
        this->shared_data.push_back(i);
        mx.unlock();
        for (auto v :shared_data) {
            std::cout << "value: " << v << " ";
        }
        std::cout << std::endl;
    }
};

void test_mutex() {
    MutexTest mxt;
    std::thread t1(&MutexTest::push_data, &mxt, 2);
    std::thread t2(&MutexTest::push_data, &mxt, 10);
    t1.join();
    t2.join();
}


class TimedMutexTest {
    std::timed_mutex mx;
    std::vector<int> shared_data{0};
public:
    void push_data(int i) {
        // mx.unlock(); //这个unlock会影响try_lock_for，如果这里unlock了，则下面两个都可以获取到锁，有BUG
        bool t = mx.try_lock_for(std::chrono::milliseconds (1));
        std::cout << "try lock: " << t << std::endl;
        if (t) {
            std::cout << "this this thread: " << std::this_thread::get_id() << std::endl;
            this->shared_data.push_back(i);
            std::this_thread::sleep_for(std::chrono::seconds(5));
            mx.unlock();
            for (auto v :shared_data) {
                std::cout << "value: " << v << " ";
            }
            std::cout << std::endl;
        }
    }
};

void test_timed_mutex() {
    TimedMutexTest mxt;
    std::thread t1(&TimedMutexTest::push_data, &mxt, 2);
    std::thread t2(&TimedMutexTest::push_data, &mxt, 10);
    t1.join();
    t2.join();
}

#endif //MODERNTEST_MUTEX_TEST_H
