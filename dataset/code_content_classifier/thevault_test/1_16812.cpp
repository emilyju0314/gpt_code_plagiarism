TEST(basics)
{
    allocator* alloc = nullptr;
    psock* s = nullptr;
    const char* buffer = "TEST";
    size_t buffer_size = strlen(buffer);
    char read_buffer[1];
    size_t read_size;

    /* we should be able to create a malloc allocator. */
    TEST_ASSERT(
        STATUS_SUCCESS == malloc_allocator_create(&alloc));

    /* we should be able to create a psock from the buffer. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            psock_create_from_buffer(
                &s, alloc, buffer, buffer_size));

    /* we can read a T. */
    read_size = sizeof(read_buffer);
    TEST_ASSERT(STATUS_SUCCESS == psock_read_raw(s, &read_buffer, &read_size));
    TEST_ASSERT(1U == read_size);
    TEST_EXPECT('T' == read_buffer[0]);

    /* we can read an E. */
    read_size = sizeof(read_buffer);
    TEST_ASSERT(STATUS_SUCCESS == psock_read_raw(s, &read_buffer, &read_size));
    TEST_ASSERT(1U == read_size);
    TEST_EXPECT('E' == read_buffer[0]);

    /* we can read an S. */
    read_size = sizeof(read_buffer);
    TEST_ASSERT(STATUS_SUCCESS == psock_read_raw(s, &read_buffer, &read_size));
    TEST_ASSERT(1U == read_size);
    TEST_EXPECT('S' == read_buffer[0]);

    /* we can read a T. */
    read_size = sizeof(read_buffer);
    TEST_ASSERT(STATUS_SUCCESS == psock_read_raw(s, &read_buffer, &read_size));
    TEST_ASSERT(1U == read_size);
    TEST_EXPECT('T' == read_buffer[0]);

    /* The last read ends in EOF. */
    read_size = sizeof(read_buffer);
    TEST_ASSERT(
        ERROR_PSOCK_READ_EOF == psock_read_raw(s, &read_buffer, &read_size));

    /* we should be able to release the socket, which in turn will close the lhs
     * descriptor. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            resource_release(psock_resource_handle(s)));

    /* clean up. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(allocator_resource_handle(alloc)));
}