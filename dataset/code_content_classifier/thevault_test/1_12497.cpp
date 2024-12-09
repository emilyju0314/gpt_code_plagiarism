Node* Node::Clone(Skeleton* skeleton) const
    {
        Node* result = Node::Create(m_nameId, skeleton);

        // copy attributes
        result->m_parentIndex        = m_parentIndex;
        result->m_nodeIndex          = m_nodeIndex;
        result->m_skeletalLoDs       = m_skeletalLoDs;
        result->m_childIndices       = m_childIndices;
        result->m_nodeFlags          = m_nodeFlags;
        result->m_semanticNameId     = m_semanticNameId;

        // copy the node attributes
        result->m_attributes.reserve(m_attributes.size());
        for (const NodeAttribute* attribute : m_attributes)
        {
            result->AddAttribute(attribute->Clone());
        }

        // return the resulting clone
        return result;
    }