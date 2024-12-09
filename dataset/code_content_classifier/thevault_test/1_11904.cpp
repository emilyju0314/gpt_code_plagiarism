void Actor::RemoveAllNodeMeshes()
    {
        const size_t numNodes = m_skeleton->GetNumNodes();

        AZStd::vector<LODLevel>& lodLevels = m_meshLodData.m_lodLevels;
        for (LODLevel& lodLevel : lodLevels)
        {
            for (size_t i = 0; i < numNodes; ++i)
            {
                NodeLODInfo& info = lodLevel.m_nodeInfos[i];
                MCore::Destroy(info.m_mesh);
                info.m_mesh = nullptr;
                MCore::Destroy(info.m_stack);
                info.m_stack = nullptr;
            }
        }
    }