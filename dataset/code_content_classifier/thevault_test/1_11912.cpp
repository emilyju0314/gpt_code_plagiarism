bool Actor::MapNodeMotionSource(const char* sourceNodeName, const char* destNodeName)
    {
        // find the source node index
        const size_t sourceNodeIndex = m_skeleton->FindNodeByNameNoCase(sourceNodeName)->GetNodeIndex();
        if (sourceNodeIndex == InvalidIndex)
        {
            return false;
        }

        // find the dest node index
        const size_t destNodeIndex = m_skeleton->FindNodeByNameNoCase(destNodeName)->GetNodeIndex();
        if (destNodeIndex == InvalidIndex)
        {
            return false;
        }

        // allocate the data if we haven't already
        if (m_nodeMirrorInfos.empty())
        {
            AllocateNodeMirrorInfos();
        }

        // apply the mapping
        m_nodeMirrorInfos[ destNodeIndex   ].m_sourceNode = static_cast<uint16>(sourceNodeIndex);
        m_nodeMirrorInfos[ sourceNodeIndex ].m_sourceNode = static_cast<uint16>(destNodeIndex);

        // we succeeded, because both source and dest have been found
        return true;
    }