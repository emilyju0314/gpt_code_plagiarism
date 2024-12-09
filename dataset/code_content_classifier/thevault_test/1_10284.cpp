bool
    detectCollision(Component::GridCollider const& rGridCollider,
                    Component::Collider const& rCollider,
                    int gridOffsetX,
                    int gridOffsetY,
                    int offsetX,
                    int offsetY)
    {
        for (auto const& rColliderRectangle : rCollider.m_colliderRectangles)
            if (detectCollision(rGridCollider,
                                rColliderRectangle,
                                gridOffsetX,
                                gridOffsetY,
                                offsetX,
                                offsetY))
                return true;
        return false;
    }