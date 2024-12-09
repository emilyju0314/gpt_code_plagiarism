TEST(basics)
{
    allocator* alloc = nullptr;
    fiber_scheduler* sched = nullptr;
    fiber* manager = nullptr;
    fiber* dummy = nullptr;
    management_fiber_context mgmnt_ctx;

    /* clear the management context. */
    memset(&mgmnt_ctx, 0, sizeof(mgmnt_ctx));

    /* we should be able to create a malloc allocator. */
    TEST_ASSERT(
        STATUS_SUCCESS == malloc_allocator_create(&alloc));

    /* we should be able to create a disciplined fiber scheduler. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            fiber_scheduler_create_with_disciplines(&sched, alloc));

    /* save the scheduler in the context structure. */
    mgmnt_ctx.sched = sched;

    /* we should be able to find the management discipline. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            fiber_scheduler_discipline_find(
                &mgmnt_ctx.mgmnt_disc, sched,
                &FIBER_SCHEDULER_MANAGEMENT_DISCIPLINE));

    /* create the manager fiber. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            fiber_create(
                &manager, alloc, sched, 16384, &mgmnt_ctx, &manager_main));

    /* add the manager fiber to the scheduler. */
    TEST_ASSERT(STATUS_SUCCESS == fiber_scheduler_add(sched, manager));

    /* run the scheduler to ensure the manager fiber yields. */
    TEST_ASSERT(STATUS_SUCCESS == fiber_scheduler_run(sched));

    /* PRECONDITIONS: the counts should all be zero. */
    TEST_ASSERT(0 == mgmnt_ctx.fiber_add_count);
    TEST_ASSERT(0 == mgmnt_ctx.fiber_stop_count);
    TEST_ASSERT(0 == mgmnt_ctx.fiber_error_count);

    /* create the dummy fiber. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            fiber_create(
                &dummy, alloc, sched, 16384, nullptr, &dummy_main));

    /* add the dummy fiber to the scheduler. */
    TEST_ASSERT(STATUS_SUCCESS == fiber_scheduler_add(sched, dummy));

    /* POSTCONDITIONS: the add count should be one, and the stop count should be
     * zero. */
    TEST_EXPECT(1 == mgmnt_ctx.fiber_add_count);
    TEST_EXPECT(0 == mgmnt_ctx.fiber_stop_count);
    TEST_ASSERT(0 == mgmnt_ctx.fiber_error_count);

    /* run the scheduler. */
    TEST_ASSERT(STATUS_SUCCESS == fiber_scheduler_run(sched));

    /* POSTCONDITIONS: the counts should all be one. */
    TEST_EXPECT(1 == mgmnt_ctx.fiber_add_count);
    TEST_EXPECT(1 == mgmnt_ctx.fiber_stop_count);
    TEST_ASSERT(0 == mgmnt_ctx.fiber_error_count);

    /* clean up. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            resource_release(fiber_scheduler_resource_handle(sched)));
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(allocator_resource_handle(alloc)));
}