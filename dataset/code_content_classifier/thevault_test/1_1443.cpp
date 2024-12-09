static cart_leaf* maximum(const cart_node *n) {
    // Handle base cases
    if (!n) return NULL;
    if (IS_LEAF(n)) return LEAF_RAW(n);

    int idx;
    switch (n->type) {
        case NODE4:
            return maximum(((const cart_node4*)n)->children[n->num_children-1]);
        case NODE16:
            return maximum(((const cart_node16*)n)->children[n->num_children-1]);
        case NODE48:
            idx=255;
            while (!((const cart_node48*)n)->keys[idx]) idx--;
            idx = ((const cart_node48*)n)->keys[idx] - 1;
            return maximum(((const cart_node48*)n)->children[idx]);
        case NODE256:
            idx=255;
            while (!((const cart_node256*)n)->children[idx]) idx--;
            return maximum(((const cart_node256*)n)->children[idx]);
        default:
            abort();
    }
}