TEST(wait_signal_all)
{
    allocator* alloc = nullptr;
    thread* one = nullptr;
    thread* two = nullptr;
    thread* three = nullptr;
    thread_mutex* mut = nullptr;
    thread_cond* cond = nullptr;
    threadstuff ts;
    int waiters;
    int val;

    /* clear thread context. */
    memset(&ts, 0, sizeof(ts));

    /* we should be able to create a malloc allocator. */
    TEST_ASSERT(STATUS_SUCCESS == malloc_allocator_create(&alloc));

    /* we should be able to create a thread cond. */
    TEST_ASSERT(STATUS_SUCCESS == thread_cond_create(&cond, alloc));

    /* we should be able to create a thread mutex. */
    TEST_ASSERT(STATUS_SUCCESS == thread_mutex_create(&mut, alloc));

    /* copy these resources to ts. */
    ts.mut = mut;
    ts.cond = cond;

    /* precondition: val is 0. */
    TEST_ASSERT(STATUS_SUCCESS == read_val(&ts, &val));
    TEST_ASSERT(0 == val);

    /* precondition: there are no waiters. */
    TEST_ASSERT(STATUS_SUCCESS == read_waiters(&ts, &waiters));
    TEST_ASSERT(0 == waiters);

    /* create thread one. */
    TEST_ASSERT(
        STATUS_SUCCESS == thread_create(&one, alloc, 16384, &ts, &incr));

    /* wait until the thread is blocking. */
    TEST_ASSERT(STATUS_SUCCESS == wait_on_waiters(&ts, 1));

    /* val is still zero. */
    TEST_ASSERT(STATUS_SUCCESS == read_val(&ts, &val));
    TEST_ASSERT(0 == val);

    /* create thread two. */
    TEST_ASSERT(
        STATUS_SUCCESS == thread_create(&two, alloc, 16384, &ts, &incr));

    /* wait until the thread is blocking. */
    TEST_ASSERT(STATUS_SUCCESS == wait_on_waiters(&ts, 2));

    /* val is still zero. */
    TEST_ASSERT(STATUS_SUCCESS == read_val(&ts, &val));
    TEST_ASSERT(0 == val);

    /* create thread three. */
    TEST_ASSERT(
        STATUS_SUCCESS == thread_create(&three, alloc, 16384, &ts, &incr));

    /* wait until the thread is blocking. */
    TEST_ASSERT(STATUS_SUCCESS == wait_on_waiters(&ts, 3));

    /* val is still zero. */
    TEST_ASSERT(STATUS_SUCCESS == read_val(&ts, &val));
    TEST_ASSERT(0 == val);

    /* signal all threads. */
    TEST_ASSERT(
        STATUS_SUCCESS == signal_all_threads(&ts));

    /* wait until all threads are unblocked. */
    TEST_ASSERT(STATUS_SUCCESS == wait_on_waiters(&ts, 0));

    /* val is three. */
    TEST_ASSERT(STATUS_SUCCESS == read_val(&ts, &val));
    TEST_ASSERT(3 == val);

    /* release (join) thread one. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(thread_resource_handle(one)));

    /* release (join) thread two. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(thread_resource_handle(two)));

    /* release (join) thread three. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(thread_resource_handle(three)));

    /* release the mutex. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(thread_mutex_resource_handle(mut)));

    /* release the condition variable. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(thread_cond_resource_handle(cond)));

    /* clean up. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(allocator_resource_handle(alloc)));
}