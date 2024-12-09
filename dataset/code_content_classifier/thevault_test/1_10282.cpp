bool
    detectCollision(int lhsOffsetX,
                    int lhsOffsetY,
                    int rhsOffsetX,
                    int rhsOffsetY,
                    Component::ColliderRectangle const& rLhsRect,
                    Component::ColliderRectangle const& rRhsRect)
    {
        return rLhsRect.m_pos[0] + lhsOffsetX < rRhsRect.m_pos[0] + rRhsRect.m_dim[0] + rhsOffsetX
            && rRhsRect.m_pos[0] + rhsOffsetX < rLhsRect.m_pos[0] + rLhsRect.m_dim[0] + lhsOffsetX
            && rLhsRect.m_pos[1] + lhsOffsetY < rRhsRect.m_pos[1] + rRhsRect.m_dim[1] + rhsOffsetY
            && rRhsRect.m_pos[1] + rhsOffsetY < rLhsRect.m_pos[1] + rLhsRect.m_dim[1] + lhsOffsetY;
    }