static int
RTreeInsertRect2(struct Rect *r, int tid, struct Node *n, struct Node **new_node, int level)
{
    /*
            register struct Rect *r = R;
            register int tid = Tid;
            register struct Node *n = N, **new_node = New_node;
            register int level = Level;
     */

    register int i;
    struct Branch b;
    struct Node *n2;

    assert(r && n && new_node);
    assert(level >= 0 && level <= n->level);

    // Still above level for insertion, go down tree recursively
    if (n->level > level) {
        i = RTreePickBranch(r, n);
        if (!RTreeInsertRect2(r, tid, n->branch[i].child, &n2, level)) {
            // child was not split
            n->branch[i].rect = RTreeCombineRect(r, &(n->branch[i].rect));
            return 0;
        } else { // child was split
            n->branch[i].rect = RTreeNodeCover(n->branch[i].child);
            b.child = n2;
            b.rect = RTreeNodeCover(n2);
            return RTreeAddBranch(&b, n, new_node);
        }
    } else if (n->level == level) {
        /* Have reached level for insertion. Add rect, split if necessary */
        b.rect = *r;
        b.child = (struct Node *) tid;
        /* child field of leaves contains tid of data record */
        return RTreeAddBranch(&b, n, new_node);
    } else { /* Not supposed to happen */
        assert(FALSE);
        return 0;
    }
}