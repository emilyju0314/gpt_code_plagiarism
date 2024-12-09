void
    trie::create_fast_transitions(node *n) {
        for (unsigned c = 0; c < NODE_CHILD_COUNT; c++) {
            node *next = n->next(c);
            if (next) {
                create_fast_transitions(next);
            } else {
                node *q = n;
                do {
                    q = q->fail();
                } while (q && !q->next(c));
                n->next(c, (q ? q->next(c) : coalesce(_root->next(c), _root)));
            }
        }
    }