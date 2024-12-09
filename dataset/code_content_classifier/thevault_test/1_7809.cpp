static int
RTreeDeleteRect2(struct Rect *R, int Tid, struct Node *N, struct ListNode **Ee)
{
    register struct Rect *r = R;
    register int tid = Tid;
    register struct Node *n = N;
    register struct ListNode **ee = Ee;
    register int i;

    assert(r && n && ee);
    assert(tid >= 0);
    assert(n->level >= 0);

    if (n->level > 0) { // not a leaf node
        for (i = 0; i < NODECARD; i++) {
            if (n->branch[i].child && RTreeOverlap(r, &(n->branch[i].rect))) {
                if (!RTreeDeleteRect2(r, tid, n->branch[i].child, ee)) {
                    if (n->branch[i].child->count >= MinFill)
                        n->branch[i].rect = RTreeNodeCover(
                                                           n->branch[i].child);
                    else {
                        // not enough entries in child, eliminate child node
                        RTreeReInsert(n->branch[i].child, ee);
                        RTreeDisconnectBranch(n, i);
                    }
                    return 0;
                }
            }
        }
        return 1;
    } else { // a leaf node
        for (i = 0; i < NODECARD; i++) {
            if (n->branch[i].child &&
                n->branch[i].child == (struct Node *) tid) {
                RTreeDisconnectBranch(n, i);
                return 0;
            }
        }
        return 1;
    }
}