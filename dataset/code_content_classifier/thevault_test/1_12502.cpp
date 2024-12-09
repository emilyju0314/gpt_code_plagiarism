Node* Node::FindRoot() const
    {
        size_t parentIndex = m_parentIndex;
        const Node* curNode = this;

        while (parentIndex != InvalidIndex)
        {
            curNode = m_skeleton->GetNode(parentIndex);
            parentIndex = curNode->GetParentIndex();
        }

        return const_cast<Node*>(curNode);
    }