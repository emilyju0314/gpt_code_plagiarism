TEST(basics)
{
    allocator* alloc = nullptr;
    fiber_scheduler* sched = nullptr;
    fiber* fib = nullptr;
    fiber_scheduler_disciplined_context* ctx;

    /* we should be able to create a malloc allocator. */
    TEST_ASSERT(
        STATUS_SUCCESS == malloc_allocator_create(&alloc));

    /* we should be able to create a disciplined fiber scheduler. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            fiber_scheduler_create_with_disciplines(&sched, alloc));

    /* we should be able to create a dummy thread fiber. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            fiber_create_for_thread(&fib, sched, alloc));

    /* PRECONDITION: the idle fiber is NOT set. */
    ctx = (fiber_scheduler_disciplined_context*)sched->context;
    TEST_ASSERT(nullptr == ctx->idle_fiber);

    /* set the idle fiber. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            disciplined_fiber_scheduler_set_idle_fiber(sched, fib));

    /* POSTCONDITION: the idle fiber is set. */
    TEST_EXPECT(fib == ctx->idle_fiber);

    /* clean up. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            resource_release(fiber_scheduler_resource_handle(sched)));
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(allocator_resource_handle(alloc)));
}