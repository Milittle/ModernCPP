//
// Created by milittle on 2022/4/3.
//

#ifndef MODERNTEST_FOLLYTEST_H
#define MODERNTEST_FOLLYTEST_H

#include <iostream>

#include <folly/futures/Future.h>
#include <folly/executors/ThreadedExecutor.h>

void foo(int x) {
    // do something with x
    std::cout << "foo(" << x << ")" << std::endl;
}

void folly_test01() {
    folly::ThreadedExecutor executor;
    std::cout << "making Promise" << std::endl;
    folly::Promise<int> p;
    folly::Future<int> f = p.getSemiFuture().via(&executor);
    auto f2 = std::move(f).thenValue(foo);
    std::cout << "Future chain made" << std::endl;

    //now perhaps in another event callback

    std::cout << "fulfilling Promise" << std::endl;
    p.setValue(42);
    std::move(f2).get();
    std::cout << "Promise fulfilled" << std::endl;
}

#endif //MODERNTEST_FOLLYTEST_H
