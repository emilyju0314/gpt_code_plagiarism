void AnimGraphNodeGroup::SetName(const char* groupName)
    {
        if (groupName)
        {
            m_name = groupName;
        }
        else
        {
            m_name.clear();
        }
    }