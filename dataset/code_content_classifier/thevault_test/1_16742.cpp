TEST(sixteen_k)
{
    allocator* alloc = nullptr;
    psock* s = nullptr;
    char* input_buffer;
    size_t input_buffer_size = 16384;
    char* output_buffer = nullptr;
    size_t output_buffer_size = 0;

    /* we should be able to create a malloc allocator. */
    TEST_ASSERT(
        STATUS_SUCCESS == malloc_allocator_create(&alloc));

    /* we should be able to create an input buffer. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            allocator_allocate(
                alloc, (void**)&input_buffer, input_buffer_size));

    /* set the data in this buffer. */
    memset(input_buffer, 'a', input_buffer_size);

    /* we should be able to create an output buffer psock instance. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            psock_create_from_buffer(
                &s, alloc, NULL, 0));

    /* we can write the expected buffer. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            psock_write_raw_data(s, input_buffer, input_buffer_size));

    /* we can get the output buffer. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            psock_from_buffer_get_output_buffer(
                s, alloc, (void**)&output_buffer, &output_buffer_size));
    TEST_ASSERT(nullptr != output_buffer);
    TEST_ASSERT(input_buffer_size == output_buffer_size);
    TEST_EXPECT(
        0 == memcmp(output_buffer, input_buffer, input_buffer_size));

    /* clean up the allocated memory for the input buffer. */
    TEST_ASSERT(STATUS_SUCCESS == allocator_reclaim(alloc, input_buffer));

    /* clean up the allocated memory for the output buffer. */
    TEST_ASSERT(STATUS_SUCCESS == allocator_reclaim(alloc, output_buffer));

    /* we should be able to release the socket, which in turn will close the lhs
     * descriptor. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            resource_release(psock_resource_handle(s)));

    /* clean up. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(allocator_resource_handle(alloc)));
}