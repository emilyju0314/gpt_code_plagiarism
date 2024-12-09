void Node::RecursiveCountChildNodes(size_t& numNodes)
    {
        // increase the counter
        numNodes++;

        // recurse down the hierarchy
        for (size_t childIndex : m_childIndices)
        {
            m_skeleton->GetNode(childIndex)->RecursiveCountChildNodes(numNodes);
        }
    }