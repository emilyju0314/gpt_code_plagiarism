TEST(bad_write_input_stream)
{
    allocator* alloc = nullptr;
    psock* s = nullptr;
    const char* foo = "foo bar";
    size_t foo_size = strlen(foo) + 1;
    char* output_buffer = nullptr;
    size_t output_buffer_size = 0;

    /* we should be able to create a malloc allocator. */
    TEST_ASSERT(
        STATUS_SUCCESS == malloc_allocator_create(&alloc));

    /* we should be able to create an input buffer psock instance. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            psock_create_from_buffer(
                &s, alloc, foo, foo_size));

    /* It's an error to write to this buffer. */
    TEST_EXPECT(
        ERROR_PSOCK_UNSUPPORTED_TYPE ==
            psock_write_raw_data(s, foo, foo_size));

    /* it is an error to try to get the output buffer for this psock. */
    TEST_EXPECT(
        ERROR_PSOCK_UNSUPPORTED_TYPE ==
            psock_from_buffer_get_output_buffer(
                s, alloc, (void**)&output_buffer, &output_buffer_size));

    /* we should be able to release the socket, which in turn will close the lhs
     * descriptor. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            resource_release(psock_resource_handle(s)));

    /* clean up. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(allocator_resource_handle(alloc)));
}