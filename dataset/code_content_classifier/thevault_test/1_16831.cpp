TEST(basics)
{
    allocator* alloc = nullptr;
    thread* th = nullptr;
    threadstuff ts;

    /* clear thread context. */
    memset(&ts, 0, sizeof(ts));

    /* we should be able to create a malloc allocator. */
    TEST_ASSERT(STATUS_SUCCESS == malloc_allocator_create(&alloc));

    /* precondition: val is 0. */
    TEST_ASSERT(0 == ts.val);

    /* we should be able to create a thread. */
    TEST_ASSERT(STATUS_SUCCESS == thread_create(&th, alloc, 16384, &ts, &incr));

    /* join the thread. */
    TEST_ASSERT(
        ERROR_SOCKET_UTILITIES_SOCKETPAIR_FAILURE ==
            resource_release(thread_resource_handle(th)));

    /* postcondition: val is 1. */
    TEST_EXPECT(1 == ts.val);

    /* clean up. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(allocator_resource_handle(alloc)));
}