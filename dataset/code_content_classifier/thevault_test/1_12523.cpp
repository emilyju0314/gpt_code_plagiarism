bool MorphTargetStandard::Influences(size_t nodeIndex) const
    {
        return
            AZStd::any_of(begin(m_deformDatas), end(m_deformDatas), [nodeIndex](const DeformData* deformData)
            {
                return deformData->m_nodeIndex == nodeIndex;
            })
            ||
            AZStd::any_of(begin(m_transforms), end(m_transforms), [nodeIndex](const Transformation& transform)
            {
                return transform.m_nodeIndex == nodeIndex;
            });
    }