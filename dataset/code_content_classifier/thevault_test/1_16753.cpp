TEST(notify_one_multiple)
{
    allocator* alloc = nullptr;
    fiber_scheduler* sched = nullptr;
    fiber_scheduler_discipline* condisc = nullptr;
    fiber* fib1 = nullptr;
    fiber* fib2 = nullptr;
    conditional cond = -1;
    test_fiber_context ctx1;
    test_fiber_context ctx2;

    /* we should be able to create a malloc allocator. */
    TEST_ASSERT(STATUS_SUCCESS == malloc_allocator_create(&alloc));

    /* we should be able to create a disciplined fiber scheduler. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            fiber_scheduler_create_with_disciplines(&sched, alloc));

    /* we should be able to create the condition discipline. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            condition_discipline_get_or_create(&condisc, alloc, sched));

    /* we should be able to create a conditional. */
    TEST_ASSERT(STATUS_SUCCESS == conditional_create(&cond, condisc));

    /* clear the first test context. */
    memset(&ctx1, 0, sizeof(test_fiber_context));

    /* clear the second test context. */
    memset(&ctx2, 0, sizeof(test_fiber_context));

    /* set first context values. */
    ctx1.cond = cond;
    ctx1.condisc = condisc;

    /* set second context values. */
    ctx2.cond = cond;
    ctx2.condisc = condisc;

    /* we should be able to create the first fiber instance. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            fiber_create(
                &fib1, alloc, sched, 16384, &ctx1, &test_fiber_entry));

    /* we should be able to create the second fiber instance. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            fiber_create(
                &fib2, alloc, sched, 16384, &ctx2, &test_fiber_entry));

    /* we should be able to add the first fiber to the scheduler. */
    TEST_ASSERT(STATUS_SUCCESS == fiber_scheduler_add(sched, fib1));

    /* we should be able to add the second fiber to the scheduler. */
    TEST_ASSERT(STATUS_SUCCESS == fiber_scheduler_add(sched, fib2));

    /* run the scheduler. */
    TEST_ASSERT(STATUS_SUCCESS == fiber_scheduler_run(sched));

    /* precondition: the first context state should be STARTED. */
    TEST_ASSERT(TEST_FIBER_STATE_STARTED == ctx1.state);

    /* precondition: the second context state should be STARTED. */
    TEST_ASSERT(TEST_FIBER_STATE_STARTED == ctx2.state);

    /* notify one fiber to start. */
    TEST_ASSERT(STATUS_SUCCESS == conditional_notify_one(cond, condisc));

    /* postcondition: the first context state should be FINISHED. */
    TEST_ASSERT(TEST_FIBER_STATE_FINISHED == ctx1.state);

    /* precondition: the second context state is still STARTED. */
    TEST_ASSERT(TEST_FIBER_STATE_STARTED == ctx2.state);

    /* notify one fiber to start. */
    TEST_ASSERT(STATUS_SUCCESS == conditional_notify_one(cond, condisc));

    /* postcondition: the second context state should be FINISHED. */
    TEST_ASSERT(TEST_FIBER_STATE_FINISHED == ctx2.state);

    /* clean up. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            resource_release(fiber_scheduler_resource_handle(sched)));
    TEST_ASSERT(
        STATUS_SUCCESS ==
            resource_release(allocator_resource_handle(alloc)));
}