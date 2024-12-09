Node* Node::GetParentNode() const
    {
        if (m_parentIndex != InvalidIndex)
        {
            return m_skeleton->GetNode(m_parentIndex);
        }

        return nullptr;
    }