#include "meta/meta.h"
#include "thread/call_once.h"
#include "thread/recursive_mutex_test.h"
#include "thread/unique_lock.h"
#include "thread/mutex_test.h"
#include "thread/shared_mutext_test.h"

int main()
{
    shared_mutex_test();
    //test_mutex();
}
