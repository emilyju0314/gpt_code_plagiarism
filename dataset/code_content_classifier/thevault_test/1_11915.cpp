void Actor::GenerateUpdatePathToRoot(size_t endNodeIndex, AZStd::vector<size_t>& outPath) const
    {
        outPath.clear();
        outPath.reserve(32);

        // start at the end effector
        Node* currentNode = m_skeleton->GetNode(endNodeIndex);
        while (currentNode)
        {
            // add the current node to the update list
            outPath.emplace_back(currentNode->GetNodeIndex());

            // move up the hierarchy, towards the root and end node
            currentNode = currentNode->GetParentNode();
        }
    }