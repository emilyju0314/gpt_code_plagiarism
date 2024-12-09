Node* Skeleton::FindNodeByNameNoCase(const char* name) const
    {
        // check the names for all nodes
        const auto foundNode = AZStd::find_if(begin(m_nodes), end(m_nodes), [name](const Node* node)
        {
            return AzFramework::StringFunc::Equal(node->GetNameString(), name, false /* no case */);
        });
        return foundNode != end(m_nodes) ? *foundNode : nullptr;
    }