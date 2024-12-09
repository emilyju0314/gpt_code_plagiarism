TEST(accept)
{
    allocator* alloc = nullptr;
    psock* s = nullptr;
    const char* buffer = "this is a test.";
    size_t buffer_size = strlen(buffer);
    int desc;
    struct sockaddr addr;
    socklen_t addrlen;

    /* we should be able to create a malloc allocator. */
    TEST_ASSERT(
        STATUS_SUCCESS == malloc_allocator_create(&alloc));

    /* we should be able to create a psock from the buffer. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            psock_create_from_buffer(
                &s, alloc, buffer, buffer_size));

    /* accept always fails. */
    TEST_EXPECT(
        ERROR_PSOCK_UNSUPPORTED_TYPE
            == psock_accept(s, &desc, &addr, &addrlen));

    /* we should be able to release the socket, which in turn will close the lhs
     * descriptor. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            resource_release(psock_resource_handle(s)));

    /* clean up. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(allocator_resource_handle(alloc)));
}