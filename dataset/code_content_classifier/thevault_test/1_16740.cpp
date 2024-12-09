TEST(basics)
{
    allocator* alloc = nullptr;
    psock* s = nullptr;
    const char* EXPECTED_BUFFER = "TEST";
    size_t EXPECTED_BUFFER_SIZE = strlen(EXPECTED_BUFFER) + 1;
    char* output_buffer = nullptr;
    size_t output_buffer_size = 0;

    /* we should be able to create a malloc allocator. */
    TEST_ASSERT(
        STATUS_SUCCESS == malloc_allocator_create(&alloc));

    /* we should be able to create an output buffer psock instance. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            psock_create_from_buffer(
                &s, alloc, NULL, 0));

    /* we can write the expected buffer. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            psock_write_raw_data(s, EXPECTED_BUFFER, EXPECTED_BUFFER_SIZE));

    /* we can get the output buffer. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            psock_from_buffer_get_output_buffer(
                s, alloc, (void**)&output_buffer, &output_buffer_size));
    TEST_ASSERT(nullptr != output_buffer);
    TEST_ASSERT(EXPECTED_BUFFER_SIZE == output_buffer_size);
    TEST_EXPECT(
        0 == memcmp(output_buffer, EXPECTED_BUFFER, EXPECTED_BUFFER_SIZE));

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