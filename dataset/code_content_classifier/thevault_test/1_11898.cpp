bool Actor::GetHasMirrorAxesDetected() const
    {
        if (m_nodeMirrorInfos.empty())
        {
            return false;
        }

        return AZStd::all_of(begin(m_nodeMirrorInfos), end(m_nodeMirrorInfos), [](const NodeMirrorInfo& nodeMirrorInfo)
        {
            return nodeMirrorInfo.m_axis != MCORE_INVALIDINDEX8;
        });
    }