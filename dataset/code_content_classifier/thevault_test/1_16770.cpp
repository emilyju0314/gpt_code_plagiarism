TEST(alloc_realloc_free)
{
    allocator* alloc = nullptr;
    int* arr = nullptr;

    /* we can create a malloc allocator. */
    TEST_ASSERT(
        STATUS_SUCCESS == malloc_allocator_create(&alloc));

    /* we can allocate an array. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            allocator_allocate(alloc, (void**)&arr, 10*sizeof(int)));

    /* we can resize the array larger. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            allocator_reallocate(alloc, (void**)&arr, 20*sizeof(int)));

    /* we can resize the array smaller. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            allocator_reallocate(alloc, (void**)&arr, 5*sizeof(int)));

    /* we can reclaim the array. */
    TEST_ASSERT(
        STATUS_SUCCESS == allocator_reclaim(alloc, arr));

    /* we can release this resource. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(allocator_resource_handle(alloc)));
}