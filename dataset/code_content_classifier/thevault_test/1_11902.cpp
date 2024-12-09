void Actor::CopyLODLevel(Actor* copyActor, size_t copyLODLevel, size_t replaceLODLevel, bool copySkeletalLODFlags)
    {
        AZStd::vector<LODLevel>& lodLevels = m_meshLodData.m_lodLevels;
        AZStd::vector<LODLevel>& copyLodLevels = copyActor->m_meshLodData.m_lodLevels;

        const LODLevel& sourceLOD = copyLodLevels[copyLODLevel];
        LODLevel& targetLOD = lodLevels[replaceLODLevel];

        const size_t numNodes = m_skeleton->GetNumNodes();
        for (size_t i = 0; i < numNodes; ++i)
        {
            Node* node     = m_skeleton->GetNode(i);
            Node* copyNode = copyActor->GetSkeleton()->FindNodeByID(node->GetID());

            if (copyNode == nullptr)
            {
                MCore::LogWarning("Actor::CopyLODLevel() - Failed to find node '%s' in the actor we want to copy from.", node->GetName());
            }

            const NodeLODInfo& sourceNodeInfo = sourceLOD.m_nodeInfos[ copyNode->GetNodeIndex() ];
            NodeLODInfo& targetNodeInfo = targetLOD.m_nodeInfos[i];

            // first get rid of existing data
            MCore::Destroy(targetNodeInfo.m_mesh);
            targetNodeInfo.m_mesh        = nullptr;
            MCore::Destroy(targetNodeInfo.m_stack);
            targetNodeInfo.m_stack       = nullptr;

            // if the node exists in both models
            if (copyNode)
            {
                // copy over the mesh and collision mesh
                if (sourceNodeInfo.m_mesh)
                {
                    targetNodeInfo.m_mesh = sourceNodeInfo.m_mesh->Clone();
                }

                // handle the stacks
                if (sourceNodeInfo.m_stack)
                {
                    targetNodeInfo.m_stack = sourceNodeInfo.m_stack->Clone(targetNodeInfo.m_mesh);
                }

                // copy the skeletal LOD flag
                if (copySkeletalLODFlags)
                {
                    node->SetSkeletalLODStatus(replaceLODLevel, copyNode->GetSkeletalLODStatus(copyLODLevel));
                }
            }
        }

        // copy the materials
        const size_t numMaterials = copyActor->GetNumMaterials(copyLODLevel);
        for (Material* i : m_materials[replaceLODLevel])
        {
            i->Destroy();
        }
        m_materials[replaceLODLevel].clear();
        m_materials[replaceLODLevel].reserve(numMaterials);
        for (size_t i = 0; i < numMaterials; ++i)
        {
            AddMaterial(replaceLODLevel, copyActor->GetMaterial(copyLODLevel, i)->Clone());
        }

        // copy the morph setup
        if (m_morphSetups[replaceLODLevel])
        {
            m_morphSetups[replaceLODLevel]->Destroy();
        }

        if (copyActor->GetMorphSetup(copyLODLevel))
        {
            m_morphSetups[replaceLODLevel] = copyActor->GetMorphSetup(copyLODLevel)->Clone();
        }
        else
        {
            m_morphSetups[replaceLODLevel] = nullptr;
        }
    }