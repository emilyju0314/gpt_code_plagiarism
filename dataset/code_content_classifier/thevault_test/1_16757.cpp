TEST(remove_root)
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

    rbtree_node z;

    /* PRECONDITIONS. */
    tree->root = &z;
    z.parent = tree->nil;
    z.left = tree->nil;
    z.right = tree->nil;
    z.color = RBTREE_BLACK;
    tree->count = 1;

    /* Remove this node. */
    rbtree_remove_node(tree, &z);

    /* POSTCONDITIONS. */
    TEST_EXPECT(tree->nil == tree->root);
    TEST_EXPECT(tree->count == 0);

    /* before cleaning up rbtree, set the root to nil. */
    tree->root = tree->nil;

    /* clean up. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(rbtree_resource_handle(tree)));
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(allocator_resource_handle(alloc)));
}