TEST(remove_right_three_nodes)
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

    rbtree_node p;
    rbtree_node y;
    rbtree_node z;

    /* PRECONDITIONS. */
    tree->root = &p;
    p.parent = tree->nil;
    p.left = &z;
    p.right = &y;
    p.color = RBTREE_BLACK;
    z.parent = &p;
    z.left = tree->nil;
    z.right = tree->nil;
    z.color = RBTREE_RED;
    y.parent = &p;
    y.left = tree->nil;
    y.right = tree->nil;
    y.color = RBTREE_RED;
    tree->count = 3;

    /* Remove the child node. */
    rbtree_remove_node(tree, &y);

    /* POSTCONDITIONS. */
    TEST_EXPECT(&p == tree->root);
    TEST_EXPECT(p.parent == tree->nil);
    TEST_EXPECT(p.color == RBTREE_BLACK);
    TEST_EXPECT(p.left == &z);
    TEST_EXPECT(p.right == tree->nil);
    TEST_EXPECT(z.parent == &p);
    TEST_EXPECT(z.color == RBTREE_RED);
    TEST_EXPECT(z.left == tree->nil);
    TEST_EXPECT(z.right == tree->nil);
    TEST_EXPECT(tree->count == 2);

    /* before cleaning up rbtree, set the root to nil. */
    tree->root = tree->nil;

    /* clean up. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(rbtree_resource_handle(tree)));
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(allocator_resource_handle(alloc)));
}