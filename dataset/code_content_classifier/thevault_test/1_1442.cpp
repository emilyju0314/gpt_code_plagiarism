static cart_leaf* minimum(const cart_node *n) {
    // Handle base cases
    if (!n) return NULL;
    if (IS_LEAF(n)) return LEAF_RAW(n);

    int idx;
    switch (n->type) {
        case NODE4:
            return minimum(((const cart_node4*)n)->children[0]);
        case NODE16:
            return minimum(((const cart_node16*)n)->children[0]);
        case NODE48:
            idx=0;
            while (!((const cart_node48*)n)->keys[idx]) idx++;
            idx = ((const cart_node48*)n)->keys[idx] - 1;
            return minimum(((const cart_node48*)n)->children[idx]);
        case NODE256:
            idx=0;
            while (!((const cart_node256*)n)->children[idx]) idx++;
            return minimum(((const cart_node256*)n)->children[idx]);
        default:
            abort();
    }
}