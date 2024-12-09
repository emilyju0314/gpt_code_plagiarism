bool
    detectCollision(Component::GridCollider const& rGridCollider,
                    Component::ColliderRectangle const& rColliderRect,
                    int gridOffsetX,
                    int gridOffsetY,
                    int offsetX,
                    int offsetY)
    {
        auto const findColumn = [&](int x)
        {
            return (x - gridOffsetX) / rGridCollider.m_cellDim[0];
        };

        auto const findRow = [&](int y)
        {
            return (y - gridOffsetY) / rGridCollider.m_cellDim[1];
        };

        auto const lowerRow = findRow(offsetY + rColliderRect.m_pos[1]);
        auto const upperRow = findRow(offsetY + rColliderRect.m_pos[1] + rColliderRect.m_dim[1] - 1);
        auto const leftColumn = findColumn(offsetX + rColliderRect.m_pos[0]);
        auto const rightColumn = findColumn(offsetX + rColliderRect.m_pos[0] + rColliderRect.m_dim[0] - 1);

        for (int row = std::max(lowerRow, 0); row < std::min(upperRow + 1, rGridCollider.m_dim[1]); ++row)
        {
            for (int column = std::max(leftColumn, 0); column < std::min(rightColumn + 1, rGridCollider.m_dim[0]); ++column)
            {
                if (rGridCollider.m_occupancies.at(static_cast<size_t>(row) * rGridCollider.m_dim[0] + column))
                    return true;
            }
        }
        return false;
    }