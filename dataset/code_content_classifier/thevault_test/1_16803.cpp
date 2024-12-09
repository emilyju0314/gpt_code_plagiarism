TEST(add)
{
    allocator* alloc = nullptr;
    fiber* f = nullptr;
    fiber_scheduler* sched = nullptr;
    int dummyval = 73;

    /* we should be able to create a malloc allocator. */
    TEST_ASSERT(
        STATUS_SUCCESS == malloc_allocator_create(&alloc));

    /* we should be able to create a disciplined fiber scheduler. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            fiber_scheduler_create_with_disciplines(&sched, alloc));

    /* we should be able to create a fiber for a thread. */
    TEST_ASSERT(STATUS_SUCCESS == fiber_create_for_thread(&f, sched, alloc));

    /* PRECONDITION: fiber unexpected event callback not set. */
    TEST_ASSERT(nullptr == f->unexpected_fn);
    TEST_ASSERT(nullptr == f->unexpected_context);

    /* add a custom event callback to this fiber. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            fiber_unexpected_event_callback_add(f, &dummy_event, &dummyval));

    /* POSTCONDITION: fiber unexpected event callback is set. */
    TEST_EXPECT(&dummy_event == f->unexpected_fn);
    TEST_EXPECT(&dummyval == f->unexpected_context);

    /* clean up. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            resource_release(fiber_scheduler_resource_handle(sched)));
    TEST_ASSERT(
        STATUS_SUCCESS ==
            resource_release(fiber_resource_handle(f)));
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(allocator_resource_handle(alloc)));
}