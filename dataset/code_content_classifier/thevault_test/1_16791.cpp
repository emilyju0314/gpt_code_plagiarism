TEST(write_invalid_read_error)
{
    allocator* alloc = nullptr;
    psock* ls = nullptr;
    psock* rs = nullptr;
    int lhs;
    int rhs;
    int32_t val = 0;

    /* we should be able to create a malloc allocator. */
    TEST_ASSERT(
        STATUS_SUCCESS == malloc_allocator_create(&alloc));

    /* we should be able to create a socket pair. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            socket_utility_socketpair(AF_UNIX, SOCK_STREAM, 0, &lhs, &rhs));

    /* we should be able to create a psock from the lhs socket. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            psock_create_from_descriptor(
                &ls, alloc, lhs));

    /* we should be able to create a psock from the rhs socket. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            psock_create_from_descriptor(
                &rs, alloc, rhs));

    /* write a bad type. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            psock_write_raw_uint32(ls, PSOCK_BOXED_TYPE_BOOL));

    /* write a raw bool value. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            psock_write_raw_bool(ls, false));

    /* reading a boxed int32 value should fail. */
    TEST_ASSERT(
        ERROR_PSOCK_READ_BOXED_INVALID_TYPE ==
            psock_read_boxed_int32(rs, &val));

    /* clean up. */
    TEST_ASSERT(STATUS_SUCCESS == resource_release(psock_resource_handle(ls)));
    TEST_ASSERT(STATUS_SUCCESS == resource_release(psock_resource_handle(rs)));
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(allocator_resource_handle(alloc)));
}