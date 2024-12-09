void Actor::SetMeshDeformerStack(size_t lodLevel, size_t nodeIndex, MeshDeformerStack* stack)
    {
        AZStd::vector<LODLevel>& lodLevels = m_meshLodData.m_lodLevels;
        lodLevels[lodLevel].m_nodeInfos[nodeIndex].m_stack = stack;
    }