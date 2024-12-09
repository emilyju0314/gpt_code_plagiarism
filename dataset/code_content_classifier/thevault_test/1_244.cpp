inline void remove_branch(branch & b) {
        b.m_origin.m_branches_from.erase(b.m_ref_from);
        b.m_target.m_branches_to.erase(b.m_ref_to);
        m_branches.erase(b.m_ref);
    }