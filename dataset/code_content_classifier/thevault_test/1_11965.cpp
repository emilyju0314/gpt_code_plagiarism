size_t Skeleton::CalcHierarchyDepthForNode(size_t nodeIndex) const
    {
        size_t result = 0;
        const Node* curNode = m_nodes[nodeIndex];
        while (curNode->GetParentNode())
        {
            result++;
            curNode = curNode->GetParentNode();
        }

        return result;
    }