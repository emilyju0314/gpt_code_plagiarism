TEST(basics)
{
    allocator* alloc = nullptr;
    bigint* i = nullptr;
    bigint* clone = nullptr;

    /* we should be able to create a malloc allocator. */
    TEST_ASSERT(STATUS_SUCCESS == malloc_allocator_create(&alloc));

    /* we should be able to create a zero bigint. */
    TEST_ASSERT(STATUS_SUCCESS == bigint_create_zero(&i, alloc, 2048));

    /* we should be able to clone this bigint value. */
    TEST_ASSERT(STATUS_SUCCESS == bigint_clone(&clone, alloc, i));

    /* we should be able to release the original bigint. */
    TEST_ASSERT(STATUS_SUCCESS == resource_release(bigint_resource_handle(i)));

    /* we should be able to release the clone bigint. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(bigint_resource_handle(clone)));

    /* clean up. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(allocator_resource_handle(alloc)));
}