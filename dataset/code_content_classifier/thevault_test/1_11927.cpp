void Actor::RemoveNodeMeshForLOD(size_t lodLevel, size_t nodeIndex, bool destroyMesh)
    {
        AZStd::vector<LODLevel>& lodLevels = m_meshLodData.m_lodLevels;

        LODLevel&       lod         = lodLevels[lodLevel];
        NodeLODInfo&    nodeInfo    = lod.m_nodeInfos[nodeIndex];

        if (destroyMesh && nodeInfo.m_mesh)
        {
            MCore::Destroy(nodeInfo.m_mesh);
        }

        if (destroyMesh && nodeInfo.m_stack)
        {
            MCore::Destroy(nodeInfo.m_stack);
        }

        nodeInfo.m_mesh  = nullptr;
        nodeInfo.m_stack = nullptr;
    }