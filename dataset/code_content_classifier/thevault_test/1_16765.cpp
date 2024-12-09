TEST(fixup_example_13_4)
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

    rbtree_node node1;
    rbtree_node node2;
    rbtree_node node4;
    rbtree_node node5;
    rbtree_node node7;
    rbtree_node node8;
    rbtree_node node11;
    rbtree_node node14;
    rbtree_node node15;

    /* PRECONDITIONS. */
    tree->root = &node11;

    node11.parent = tree->nil;
    node11.left = &node2;
    node11.right = &node14;
    node11.color = RBTREE_BLACK;

    node2.parent = &node11;
    node2.left = &node1;
    node2.right = &node7;
    node2.color = RBTREE_RED;

    node1.parent = &node2;
    node1.left = tree->nil;
    node1.right = tree->nil;
    node1.color = RBTREE_BLACK;

    node7.parent = &node2;
    node7.left = &node5;
    node7.right = &node8;
    node7.color = RBTREE_BLACK;

    node8.parent = &node7;
    node8.left = tree->nil;
    node8.right = tree->nil;
    node8.color = RBTREE_RED;

    node5.parent = &node7;
    node5.left = &node4;
    node5.right = tree->nil;
    node5.color = RBTREE_RED;

    node4.parent = &node5;
    node4.left = tree->nil;
    node4.right = tree->nil;
    node4.color = RBTREE_RED;

    node14.parent = &node11;
    node14.left = tree->nil;
    node14.right = &node15;
    node14.color = RBTREE_BLACK;

    node15.parent = &node14;
    node15.left = tree->nil;
    node15.right = tree->nil;
    node15.color = RBTREE_RED;

    /* perform the insert fixup. */
    rbtree_insert_fixup(tree, &node4);

    /* POSTCONDITIONS. */
    TEST_ASSERT(&node7 == tree->root);
    TEST_ASSERT(&node2 == node7.left);
    TEST_ASSERT(&node11 == node7.right);
    TEST_ASSERT(RBTREE_BLACK == node7.color);

    TEST_ASSERT(&node7 == node2.parent);
    TEST_ASSERT(&node1 == node2.left);
    TEST_ASSERT(&node5 == node2.right);
    TEST_ASSERT(RBTREE_RED == node2.color);

    TEST_ASSERT(&node2 == node1.parent);
    TEST_ASSERT(tree->nil == node1.left);
    TEST_ASSERT(tree->nil == node1.right);
    TEST_ASSERT(RBTREE_BLACK == node1.color);

    TEST_ASSERT(&node2 == node5.parent);
    TEST_ASSERT(&node4 == node5.left);
    TEST_ASSERT(tree->nil == node5.right);
    TEST_ASSERT(RBTREE_BLACK == node5.color);

    TEST_ASSERT(&node5 == node4.parent);
    TEST_ASSERT(tree->nil == node4.left);
    TEST_ASSERT(tree->nil == node4.right);
    TEST_ASSERT(RBTREE_RED == node4.color);

    TEST_ASSERT(&node7 == node11.parent);
    TEST_ASSERT(&node8 == node11.left);
    TEST_ASSERT(&node14 == node11.right);
    TEST_ASSERT(RBTREE_RED == node11.color);

    TEST_ASSERT(&node11 == node8.parent);
    TEST_ASSERT(tree->nil == node8.left);
    TEST_ASSERT(tree->nil == node8.right);
    TEST_ASSERT(RBTREE_BLACK == node8.color);

    TEST_ASSERT(&node11 == node14.parent);
    TEST_ASSERT(tree->nil == node14.left);
    TEST_ASSERT(&node15 == node14.right);
    TEST_ASSERT(RBTREE_BLACK == node14.color);

    TEST_ASSERT(&node14 == node15.parent);
    TEST_ASSERT(tree->nil == node15.left);
    TEST_ASSERT(tree->nil == node15.right);
    TEST_ASSERT(RBTREE_RED == node15.color);

    /* before cleaning up rbtree, set the root to nil. */
    tree->root = tree->nil;

    /* clean up. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(rbtree_resource_handle(tree)));
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(allocator_resource_handle(alloc)));
}