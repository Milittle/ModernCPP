#include "meta/meta.h"
#include "thread/call_once.h"
#include "thread/recursive_mutex.h"
#include "thread/unique_lock.h"

int main()
{
    test_call_once();
    recursive_lock_test();
}
