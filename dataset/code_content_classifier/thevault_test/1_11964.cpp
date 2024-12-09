Node* Skeleton::FindNodeByID(size_t id) const
    {
        // check the ID's for all nodes
        const auto foundNode = AZStd::find_if(begin(m_nodes), end(m_nodes), [id](const Node* node)
        {
            return node->GetID() == id;
        });
        return foundNode != end(m_nodes) ? *foundNode : nullptr;
    }