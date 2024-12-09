void Actor::AddLODLevel(bool copyFromLastLODLevel)
    {
        AZStd::vector<LODLevel>& lodLevels = m_meshLodData.m_lodLevels;

        lodLevels.emplace_back();
        LODLevel& newLOD = lodLevels.back();
        const size_t numNodes = m_skeleton->GetNumNodes();
        newLOD.m_nodeInfos.resize(numNodes);

        const size_t numLODs    = lodLevels.size();
        const size_t lodIndex   = numLODs - 1;

        // get the number of nodes, iterate through them, create a new LOD level and copy over the meshes from the last LOD level
        for (size_t i = 0; i < numNodes; ++i)
        {
            NodeLODInfo& newLODInfo = lodLevels[lodIndex].m_nodeInfos[static_cast<uint32>(i)];
            if (copyFromLastLODLevel && lodIndex > 0)
            {
                const NodeLODInfo& prevLODInfo = lodLevels[lodIndex - 1].m_nodeInfos[static_cast<uint32>(i)];
                newLODInfo.m_mesh        = (prevLODInfo.m_mesh)        ? prevLODInfo.m_mesh->Clone()                    : nullptr;
                newLODInfo.m_stack       = (prevLODInfo.m_stack)       ? prevLODInfo.m_stack->Clone(newLODInfo.m_mesh)   : nullptr;
            }
            else
            {
                newLODInfo.m_mesh        = nullptr;
                newLODInfo.m_stack       = nullptr;
            }
        }

        // create a new material array for the new LOD level
        m_materials.resize(lodLevels.size());

        // create an empty morph setup for the new LOD level
        m_morphSetups.emplace_back(nullptr);

        // copy data from the previous LOD level if wanted
        if (copyFromLastLODLevel && numLODs > 0)
        {
            CopyLODLevel(this, static_cast<uint32>(lodIndex - 1), static_cast<uint32>(numLODs - 1), true);
        }
    }