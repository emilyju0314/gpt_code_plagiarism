TEST(basics)
{
    allocator* alloc = nullptr;
    rbtree* tree = nullptr;

    /* we should be able to create a malloc allocator. */
    TEST_ASSERT(
        STATUS_SUCCESS == malloc_allocator_create(&alloc));

    /* we should be able to create an rbtree instance. */
    TEST_ASSERT(
        STATUS_SUCCESS ==
            rbtree_create(&tree, alloc, &dummy_compare, &dummy_key, nullptr));

    rbtree_node u;
    rbtree_node v;

    /* PRECONDITIONS. */
    tree->root = &u;
    u.parent = tree->nil;
    u.left = &v;
    u.right = tree->nil;
    v.parent = &u;
    v.left = tree->nil;
    v.right = tree->nil;

    /* perform the transplant. */
    rbtree_transplant(tree, &u, &v);

    /* POSTCONDITIONS. */
    TEST_EXPECT(&v == tree->root);

    /* before cleaning up rbtree, set the root to nil. */
    tree->root = tree->nil;

    /* clean up. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(rbtree_resource_handle(tree)));
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(allocator_resource_handle(alloc)));
}