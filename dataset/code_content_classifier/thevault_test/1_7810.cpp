int
Rtree::RTreeDeleteRect(struct Rect *R, int Tid, struct Node**Nn)
{
    register struct Rect *r = R;
    register int tid = Tid;
    register struct Node **nn = Nn;
    register int i;
    register struct Node *tmp_node_ptr;
    struct ListNode *reInsertList = NULL;
    register struct ListNode *e;

    assert(r && nn);
    assert(*nn);
    assert(tid >= 0);

    if (!RTreeDeleteRect2(r, tid, *nn, &reInsertList)) {
        // found and deleted a data item

        // reinsert any branches from eliminated nodes
        while (reInsertList) {
            tmp_node_ptr = reInsertList->node;
            for (i = 0; i < NODECARD; i++) {
                if (tmp_node_ptr->branch[i].child) {
                    RTreeInsertRect(
                                    &(tmp_node_ptr->branch[i].rect),
                                    static_cast<uintptr_t>(reinterpret_cast<uintptr_t>(tmp_node_ptr->branch[i].child)),
                                    nn,
                                    tmp_node_ptr->level);
                }
            }
            e = reInsertList;
            reInsertList = reInsertList->next;
            RTreeFreeNode(e->node);
            RTreeFreeListNode(e);
        }

        // check for redundant root (not leaf, 1 child) and eliminate

        if ((*nn)->count == 1 && (*nn)->level > 0) {
            for (i = 0; i < NODECARD; i++) {
                tmp_node_ptr = (*nn)->branch[i].child;
                if (tmp_node_ptr)
                    break;
            }
            assert(tmp_node_ptr);
            RTreeFreeNode(*nn);
            *nn = tmp_node_ptr;
        }
        return 0;
    } else {
        return 1;
    }
}