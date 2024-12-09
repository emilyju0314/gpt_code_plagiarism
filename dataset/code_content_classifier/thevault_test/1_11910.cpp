Node* Actor::FindBestMotionExtractionNode() const
    {
        Node* result = nullptr;

        // the maximum number of children of a root node, the node with the most children
        // will become our repositioning node
        size_t maxNumChilds = 0;

        // traverse through all root nodes
        const size_t numRootNodes = m_skeleton->GetNumRootNodes();
        for (size_t i = 0; i < numRootNodes; ++i)
        {
            // get the given root node from the actor
            Node* rootNode = m_skeleton->GetNode(m_skeleton->GetRootNodeIndex(i));

            // get the number of child nodes recursively
            const size_t numChildNodes = rootNode->GetNumChildNodesRecursive();

            // if the number of child nodes of this node is bigger than the current max number
            // this is our new candidate for the repositioning node
            if (numChildNodes > maxNumChilds)
            {
                maxNumChilds = numChildNodes;
                result = rootNode;
            }
        }

        return result;
    }