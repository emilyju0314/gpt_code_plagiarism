inline void remove_node(node & n) {
        branch_ref2_t bref2;
        branch_ref2_t bend2;

        // Remove branches from the node
        bref2 = n.m_branches_from.begin();
        bend2 = n.m_branches_from.end();

        for (; bref2 != bend2; ++bref2) {
            branch_ref_t bref = *bref2;

            assert(&bref->m_origin == &n);

            bref->m_target.m_branches_to.erase(bref->m_ref_to);

            m_branches.erase(bref);
        }

        // Remove branches to the node
        bref2 = n.m_branches_to.begin();
        bend2 = n.m_branches_to.end();

        for (; bref2 != bend2; ++bref2) {
            branch_ref_t bref = *bref2;

            assert(&bref->m_target == &n);

            bref->m_origin.m_branches_from.erase(bref->m_ref_from);

            m_branches.erase(bref);
        }

        m_nodes.erase(n.m_ref);
    }