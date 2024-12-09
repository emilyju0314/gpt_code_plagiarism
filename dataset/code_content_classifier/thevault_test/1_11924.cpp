void Actor::SetMesh(size_t lodLevel, size_t nodeIndex, Mesh* mesh)
    {
        AZStd::vector<LODLevel>& lodLevels = m_meshLodData.m_lodLevels;
        lodLevels[lodLevel].m_nodeInfos[nodeIndex].m_mesh = mesh;
    }