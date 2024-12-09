size_t Actor::FindNodeGroupIndexByNameNoCase(const char* groupName) const
    {
        const auto found = AZStd::find_if(begin(m_nodeGroups), end(m_nodeGroups), [groupName](const NodeGroup* nodeGroup)
        {
            return AzFramework::StringFunc::Equal(nodeGroup->GetNameString(), groupName, false /* no case */);
        });
        return found != end(m_nodeGroups) ? AZStd::distance(begin(m_nodeGroups), found) : InvalidIndex;
    }