float GetShapeVolume(const Physics::BoxShapeConfiguration& box)
    {
        return box.m_dimensions.GetX() * box.m_dimensions.GetY() * box.m_dimensions.GetZ() *
            box.m_scale.GetX() * box.m_scale.GetY() * box.m_scale.GetZ();
    }