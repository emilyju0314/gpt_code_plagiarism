TEST(find_4_15)
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

    rbtree_node n1;
    rbtree_node n2;
    rbtree_node n3;
    rbtree_node n4;
    rbtree_node n5;
    rbtree_node n6;
    rbtree_node n7;
    rbtree_node n8;
    rbtree_node n9;
    rbtree_node n10;
    rbtree_node n11;
    rbtree_node n12;
    rbtree_node n13;
    rbtree_node n14;
    rbtree_node n15;

    /* PRECONDITIONS. */
    tree->root = &n8;
    n8.parent = tree->nil;
    n8.left = &n4;
    n8.right = &n12;
    n8.color = RBTREE_BLACK;
    n8.value = (resource*)8;
    n4.parent = &n8;
    n4.left = &n2;
    n4.right = &n6;
    n4.color = RBTREE_RED;
    n4.value = (resource*)4;
    n2.parent = &n4;
    n2.left = &n1;
    n2.right = &n3;
    n2.color = RBTREE_BLACK;
    n2.value = (resource*)2;
    n1.parent = &n2;
    n1.left = tree->nil;
    n1.right = tree->nil;
    n1.color = RBTREE_RED;
    n1.value = (resource*)1;
    n3.parent = &n2;
    n3.left = tree->nil;
    n3.right = tree->nil;
    n3.color = RBTREE_RED;
    n3.value = (resource*)3;
    n6.parent = &n4;
    n6.left = &n5;
    n6.right = &n7;
    n6.color = RBTREE_BLACK;
    n6.value = (resource*)6;
    n5.parent = &n6;
    n5.left = tree->nil;
    n5.right = tree->nil;
    n5.color = RBTREE_RED;
    n5.value = (resource*)5;
    n7.parent = &n6;
    n7.left = tree->nil;
    n7.right = tree->nil;
    n7.color = RBTREE_RED;
    n7.value = (resource*)7;
    n12.parent = &n8;
    n12.left = &n10;
    n12.right = &n14;
    n12.color = RBTREE_RED;
    n12.value = (resource*)12;
    n10.parent = &n12;
    n10.left = &n9;
    n10.right = &n11;
    n10.color = RBTREE_BLACK;
    n10.value = (resource*)10;
    n9.parent = &n10;
    n9.left = tree->nil;
    n9.right = tree->nil;
    n9.color = RBTREE_RED;
    n9.value = (resource*)9;
    n11.parent = &n10;
    n11.left = tree->nil;
    n11.right = tree->nil;
    n11.color = RBTREE_RED;
    n11.value = (resource*)11;
    n14.parent = &n12;
    n14.left = &n13;
    n14.right = &n15;
    n14.color = RBTREE_BLACK;
    n14.value = (resource*)14;
    n13.parent = &n14;
    n13.left = tree->nil;
    n13.right = tree->nil;
    n13.color = RBTREE_RED;
    n13.value = (resource*)13;
    n15.parent = &n14;
    n15.left = tree->nil;
    n15.right = tree->nil;
    n15.color = RBTREE_RED;
    n15.value = (resource*)15;

    /* Find the node. */
    resource* r;
    TEST_ASSERT(
        STATUS_SUCCESS == rbtree_find(&r, tree, (const void*)4));

    /* POSTCONDITIONS. */
    TEST_EXPECT((resource*)4 == r);

    /* before cleaning up rbtree, set the root to nil. */
    tree->root = tree->nil;

    /* clean up. */
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(rbtree_resource_handle(tree)));
    TEST_ASSERT(
        STATUS_SUCCESS == resource_release(allocator_resource_handle(alloc)));
}