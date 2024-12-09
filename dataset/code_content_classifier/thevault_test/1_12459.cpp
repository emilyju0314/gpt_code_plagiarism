bool AnimGraphNodeGroup::Contains(AnimGraphNodeId nodeId) const
    {
        const AZ::u64 convertedId = nodeId;
        return AZStd::find(m_nodeIds.begin(), m_nodeIds.end(), convertedId) != m_nodeIds.end();
    }