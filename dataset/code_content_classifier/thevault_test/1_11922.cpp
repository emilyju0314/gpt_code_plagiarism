NodeGroup* Actor::FindNodeGroupByName(const char* groupName) const
    {
        const auto found = AZStd::find_if(begin(m_nodeGroups), end(m_nodeGroups), [groupName](const NodeGroup* nodeGroup)
        {
            return nodeGroup->GetNameString() == groupName;
        });
        return found != end(m_nodeGroups) ? *found : nullptr;
    }