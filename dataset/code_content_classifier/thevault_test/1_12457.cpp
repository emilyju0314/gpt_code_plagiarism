void AnimGraphNodeGroup::AddNode(AnimGraphNodeId nodeId)
    {
        // add the node in case it is not in yet
        if (Contains(nodeId) == false)
        {
            m_nodeIds.push_back(nodeId);
        }
    }