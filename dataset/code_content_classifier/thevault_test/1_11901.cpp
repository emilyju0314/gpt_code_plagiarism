void Actor::InsertLODLevel(size_t insertAt)
    {
        AZStd::vector<LODLevel>& lodLevels = m_meshLodData.m_lodLevels;

        lodLevels.emplace(lodLevels.begin()+insertAt);
        LODLevel& newLOD = lodLevels[insertAt];
        const size_t lodIndex   = insertAt;
        const size_t numNodes   = m_skeleton->GetNumNodes();
        newLOD.m_nodeInfos.resize(numNodes);

        // get the number of nodes, iterate through them, create a new LOD level and copy over the meshes from the last LOD level
        for (size_t i = 0; i < numNodes; ++i)
        {
            NodeLODInfo& lodInfo    = lodLevels[lodIndex].m_nodeInfos[i];
            lodInfo.m_mesh           = nullptr;
            lodInfo.m_stack          = nullptr;
        }

        // create a new material array for the new LOD level
        m_materials.emplace(AZStd::next(begin(m_materials), insertAt));

        // create an empty morph setup for the new LOD level
        m_morphSetups.emplace(AZStd::next(begin(m_morphSetups), insertAt), nullptr);
    }