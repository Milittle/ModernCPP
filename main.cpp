#include "meta/meta.h"
#include "thread/call_once.h"
#include "thread/recursive_mutex_test.h"
#include "thread/unique_lock.h"
#include "thread/mutex_test.h"
#include "thread/shared_mutext_test.h"
#include "follytest/follytest.h"
#include "boosttest/test_01.h"
#include "boosttest/test_02.h"

int main()
{
//    shared_mutex_test();
//    test_mutex();
//    folly_test01();
    test_01();
    test_02();
}
