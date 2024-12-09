void AnimGraphNodeGroup::RemoveNodeById(AnimGraphNodeId nodeId)
    {
        const AZ::u64 convertedId = nodeId;
        m_nodeIds.erase(AZStd::remove(m_nodeIds.begin(), m_nodeIds.end(), convertedId), m_nodeIds.end());
    }