TEST(already_owned)
{
    allocator* alloc = nullptr;
    fiber_scheduler* sched = nullptr;
    fiber_scheduler_discipline* disc = nullptr;
    rcpr_uuid id = { .data = {
        0x0e, 0x2c, 0xfc, 0x92, 0x89, 0xfa, 0x46, 0x54,
        0xb9, 0x69, 0xd7, 0x1b, 0x18, 0x46, 0x9b, 0x4c } };
    fiber_scheduler_discipline_callback_fn emptyvec[1];

    /* we should be able to create a malloc allocator. */
    TEST_ASSERT(
        STATUS_SUCCESS == malloc_allocator_create(&alloc));

    /* we should be able to create a disciplined fiber scheduler. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            fiber_scheduler_create_with_disciplines(&sched, alloc));

    /* we should be able to create a fiber scheduler discipline. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            fiber_scheduler_discipline_create(
                &disc, &id, alloc, NULL, 0, emptyvec));

    /* force the discipline to be owned before calling. */
    disc->sched = sched;

    /* Adding the discipline should fail because the discipline is already
     * owned. */
    TEST_ASSERT(
        ERROR_FIBER_SCHEDULER_DISCIPLINE_ALREADY_OWNED ==
            fiber_scheduler_discipline_add(sched, disc));

    /* clean up. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            resource_release(fiber_scheduler_discipline_resource_handle(disc)));
    TEST_ASSERT(
        STATUS_SUCCESS ==
            resource_release(fiber_scheduler_resource_handle(sched)));
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(allocator_resource_handle(alloc)));
}