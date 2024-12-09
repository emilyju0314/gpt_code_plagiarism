size_t Node::GetNumChildNodesRecursive() const
    {
        // the number of total child nodes which include the childs of the childs, too
        size_t result = 0;

        // retrieve the number of child nodes of the actual node
        for (size_t childIndex : m_childIndices)
        {
            m_skeleton->GetNode(childIndex)->RecursiveCountChildNodes(result);
        }

        return result;
    }