TEST(basics)
{
    allocator* alloc = nullptr;
    thread_mutex* mut = nullptr;

    /* we should be able to create a malloc allocator. */
    TEST_ASSERT(STATUS_SUCCESS == malloc_allocator_create(&alloc));

    /* we should be able to create a thread mutex. */
    TEST_ASSERT(STATUS_SUCCESS == thread_mutex_create(&mut, alloc));

    /* we should be able to release a thread mutex. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(thread_mutex_resource_handle(mut)));

    /* clean up. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(allocator_resource_handle(alloc)));
}