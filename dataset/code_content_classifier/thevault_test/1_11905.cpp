void Actor::VerifySkinning(AZStd::vector<uint8>& conflictNodeFlags, size_t skeletalLODLevel, size_t geometryLODLevel)
    {
        // get the number of nodes
        const size_t numNodes = m_skeleton->GetNumNodes();

        // check if the conflict node flag array's size is set to the number of nodes inside the actor
        if (conflictNodeFlags.size() != numNodes)
        {
            conflictNodeFlags.resize(numNodes);
        }

        // reset the conflict node array to zero which means we don't have any conflicting nodes yet
        MCore::MemSet(conflictNodeFlags.data(), 0, numNodes * sizeof(int8));

        // iterate over the all nodes in the actor
        for (size_t n = 0; n < numNodes; ++n)
        {
            // get the current node and the pointer to the mesh for the given lod level
            Node* node = m_skeleton->GetNode(n);
            Mesh* mesh = GetMesh(geometryLODLevel, n);

            // skip nodes without meshes
            if (mesh == nullptr)
            {
                continue;
            }

            // find the skinning information, if it doesn't exist, skip to the next node
            SkinningInfoVertexAttributeLayer* skinningLayer = (SkinningInfoVertexAttributeLayer*)mesh->FindSharedVertexAttributeLayer(SkinningInfoVertexAttributeLayer::TYPE_ID);
            if (skinningLayer == nullptr)
            {
                continue;
            }

            // get the number of original vertices and iterate through them
            const uint32 numOrgVerts = mesh->GetNumOrgVertices();
            for (uint32 v = 0; v < numOrgVerts; ++v)
            {
                // for all influences for this vertex
                const size_t numInfluences = skinningLayer->GetNumInfluences(v);
                for (size_t i = 0; i < numInfluences; ++i)
                {
                    // get the node number of the bone
                    uint16 nodeNr = skinningLayer->GetInfluence(v, i)->GetNodeNr();

                    // if the current skinning influence is linked to a node which is disabled in the given
                    // skeletal LOD we will end up with a badly skinned character, set its flag to conflict true
                    if (node->GetSkeletalLODStatus(skeletalLODLevel) == false)
                    {
                        conflictNodeFlags[nodeNr] = 1;
                    }
                }
            }
        }
    }