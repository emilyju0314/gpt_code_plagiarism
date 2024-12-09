bool PolygonPrismShape::IsPointInside(const AZ::Vector3& point)
    {
        m_intersectionDataCache.UpdateIntersectionParams(m_currentTransform, *m_polygonPrism, m_currentNonUniformScale);

        // initial early aabb rejection test
        // note: will implicitly do height test too
        if (!GetEncompassingAabb().Contains(point))
        {
            return false;
        }

        return PolygonPrismUtil::IsPointInside(*m_polygonPrism, point, m_currentTransform);
    }