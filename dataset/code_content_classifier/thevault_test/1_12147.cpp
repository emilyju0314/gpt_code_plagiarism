CoordinateSystemConverter::CoordinateSystemConverter()
        : m_sourceTransform(AZ::Transform::CreateIdentity())
        , m_targetTransform(AZ::Transform::CreateIdentity())
        , m_conversionTransform(AZ::Transform::CreateIdentity())
        , m_conversionTransformInversed(AZ::Transform::CreateIdentity())
        , m_needsConversion(false)
        , m_sourceRightHanded(CheckIfIsRightHanded(m_sourceTransform))
        , m_targetRightHanded(CheckIfIsRightHanded(m_targetTransform))
    {
        m_targetBasisIndices[0] = 0;
        m_targetBasisIndices[1] = 1;
        m_targetBasisIndices[2] = 2;
    }