EMotionFX::Mesh::EMeshType GLActor::ClassifyMeshType(EMotionFX::Node* node, EMotionFX::Mesh* mesh, size_t lodLevel)
    {
        MCORE_ASSERT(node && mesh);
        return mesh->ClassifyMeshType(lodLevel, m_actor, node->GetNodeIndex(), !m_enableGpuSkinning, 4, 200);
    }