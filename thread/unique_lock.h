//
// Created by milittle on 2022/3/21.
//

#ifndef MODERNTEST_UNIQUE_LOCK_H
#define MODERNTEST_UNIQUE_LOCK_H

#include <mutex>
#include <thread>
#include <chrono>

struct Box {
    explicit Box(int num) : num_things{num} {}

    int num_things;
    std::mutex m;
};

void transfer(Box &from, Box &to, int num)
{
    // 仍未实际取锁
    std::unique_lock<std::mutex> lock1(from.m, std::defer_lock);
    std::unique_lock<std::mutex> lock2(to.m, std::defer_lock);

    // 锁两个 unique_lock 而不死锁
    std::lock(lock1, lock2);

    from.num_things -= num;
    to.num_things += num;

    // 'from.m' 与 'to.m' 互斥解锁于 'unique_lock' 析构函数
}

int unique_lock()
{
    Box acc1(100);
    Box acc2(50);

    std::thread t1(transfer, std::ref(acc1), std::ref(acc2), 10);
    std::thread t2(transfer, std::ref(acc2), std::ref(acc1), 5);

    t1.join();
    t2.join();
}

#endif //MODERNTEST_UNIQUE_LOCK_H
