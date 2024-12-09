TEST(output_read_fail)
{
    allocator* alloc = nullptr;
    psock* s = nullptr;
    char read_buffer[100];
    size_t read_size;

    /* we should be able to create a malloc allocator. */
    TEST_ASSERT(
        STATUS_SUCCESS == malloc_allocator_create(&alloc));

    /* we should be able to create a psock from the buffer. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            psock_create_from_buffer(
                &s, alloc, NULL, 0));

    /* read fails. */
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