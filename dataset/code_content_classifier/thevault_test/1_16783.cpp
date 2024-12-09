TEST(basics)
{
    allocator* alloc = nullptr;
    list* l = nullptr;

    /* we should be able to create a malloc allocator. */
    TEST_ASSERT(
        STATUS_SUCCESS == malloc_allocator_create(&alloc));

    /* we should be able to create a list. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            list_create(
                &l, alloc));

    /* we should be able to get the head. */
    list_node* head = nullptr;
    TEST_ASSERT(
        STATUS_SUCCESS ==
            list_head(&head, l));

    /* the head should be null. */
    TEST_ASSERT(nullptr == head);

    /* we should be able to get the tail. */
    list_node* tail = nullptr;
    TEST_ASSERT(
        STATUS_SUCCESS ==
            list_tail(&tail, l));

    /* the tail should be null. */
    TEST_ASSERT(nullptr == tail);

    /* create a resource to insert into the list. */
    allocator* other = nullptr;
    TEST_ASSERT(
        STATUS_SUCCESS == malloc_allocator_create(&other));

    /* insert this into the list. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            list_insert_head(l, allocator_resource_handle(other)));

    /* get the head / tail. */
    TEST_ASSERT(STATUS_SUCCESS == list_head(&head, l));
    TEST_ASSERT(STATUS_SUCCESS == list_tail(&tail, l));

    /* they should both be equal and not null. */
    TEST_EXPECT(nullptr != head && head == tail);

    /* get the resource associated with the head. */
    resource* r = nullptr;
    TEST_ASSERT(STATUS_SUCCESS == list_node_child(&r, head));

    /* this resource should be the same as other. */
    TEST_EXPECT(r == allocator_resource_handle(other));

    /* get the next for head. */
    list_node* head_next = nullptr;
    TEST_ASSERT(
        STATUS_SUCCESS == list_node_next(&head_next, head));

    /* head->next should be null. */
    TEST_ASSERT(nullptr == head_next);

    /* get the next for tail. */
    list_node* tail_next = nullptr;
    TEST_ASSERT(
        STATUS_SUCCESS == list_node_next(&tail_next, tail));

    /* tail->next should be null. */
    TEST_ASSERT(nullptr == tail_next);

    /* we should be able to release the list instance. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            resource_release(list_resource_handle(l)));

    /* clean up. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(allocator_resource_handle(alloc)));
}