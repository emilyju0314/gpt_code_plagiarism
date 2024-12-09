TEST(create_release)
{
    allocator* alloc = nullptr;
    resource* alloc_resource = nullptr;

    /* we can successfully create a malloc allocator. */
    TEST_ASSERT(
        STATUS_SUCCESS == malloc_allocator_create(&alloc));

    /* the allocator pointer is valid. */
    TEST_ASSERT(
        nullptr != alloc);

    /* get the allocator resource handle. */
    alloc_resource = allocator_resource_handle(alloc);

    /* this resource handle is valid. */
    TEST_ASSERT(
        nullptr != alloc_resource);

    /* we can release this resource. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(alloc_resource));
}