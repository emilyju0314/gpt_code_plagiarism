void GLActor::FillGPUSkinnedVertexBuffers(size_t lodLevel)
    {
        if (m_vertexBuffers[EMotionFX::Mesh::MESHTYPE_GPU_DEFORMED][lodLevel] == nullptr)
        {
            return;
        }

        // get the number of dynamic nodes
        const size_t numNodes = m_actor->GetNumNodes();
        if (numNodes == 0)
        {
            return;
        }

        EMotionFX::Skeleton* skeleton = m_actor->GetSkeleton();

        // lock the GPU skinned vertex buffer
        SkinnedVertex* skinnedVertices = (SkinnedVertex*)m_vertexBuffers[EMotionFX::Mesh::MESHTYPE_GPU_DEFORMED][lodLevel]->Lock(LOCK_WRITEONLY);
        if (skinnedVertices == nullptr)
        {
            return;
        }

        // copy over all vertex data of all dynamic node meshes
        uint32 globalVert = 0;

        // iterate through all nodes
        for (size_t n = 0; n < numNodes; ++n)
        {
            // get the current node
            EMotionFX::Node* node = skeleton->GetNode(n);

            // get the mesh for the node, if there is any
            EMotionFX::Mesh* mesh = m_actor->GetMesh(lodLevel, n);
            if (mesh == nullptr)
            {
                continue;
            }

            // skip collision meshes
            if (mesh->GetIsCollisionMesh())
            {
                continue;
            }

            // get the mesh type and only do gpu skinned buffers
            EMotionFX::Mesh::EMeshType meshType = ClassifyMeshType(node, mesh, lodLevel);
            if (meshType != EMotionFX::Mesh::MESHTYPE_GPU_DEFORMED)
            {
                continue;
            }

            // get the mesh data buffers
            const AZ::Vector3* positions   = static_cast<const AZ::Vector3*>(mesh->FindOriginalVertexData(EMotionFX::Mesh::ATTRIB_POSITIONS));
            const AZ::Vector3* normals     = static_cast<const AZ::Vector3*>(mesh->FindOriginalVertexData(EMotionFX::Mesh::ATTRIB_NORMALS));
            const AZ::Vector4* tangents    = static_cast<const AZ::Vector4*>(mesh->FindOriginalVertexData(EMotionFX::Mesh::ATTRIB_TANGENTS));
            const AZ::Vector2* uvsA        = static_cast<const AZ::Vector2*>(mesh->FindOriginalVertexData(EMotionFX::Mesh::ATTRIB_UVCOORDS, 0));  // first UV set
            const AZ::u32*     orgVerts    = static_cast<const AZ::u32*>(mesh->FindOriginalVertexData(EMotionFX::Mesh::ATTRIB_ORGVTXNUMBERS));

            // find the skinning layer
            EMotionFX::SkinningInfoVertexAttributeLayer* skinningInfo = (EMotionFX::SkinningInfoVertexAttributeLayer*)mesh->FindSharedVertexAttributeLayer(EMotionFX::SkinningInfoVertexAttributeLayer::TYPE_ID);
            assert(skinningInfo);

            // get the number of submeshes and iterate through them
            const size_t numSubMeshes = mesh->GetNumSubMeshes();
            for (size_t s = 0; s < numSubMeshes; ++s)
            {
                // get the current submesh and the start vertex
                EMotionFX::SubMesh* subMesh = mesh->GetSubMesh(s);
                const uint32 startVertex = subMesh->GetStartVertex();

                // get the number of vertices and iterate through them
                const uint32 numVertices = subMesh->GetNumVertices();
                for (uint32 v = 0; v < numVertices; ++v)
                {
                    const uint32 meshVertexNr = v + startVertex;
                    const uint32 orgVertex = orgVerts[meshVertexNr];

                    // copy position and normal
                    skinnedVertices[globalVert].m_position   = positions[meshVertexNr];
                    skinnedVertices[globalVert].m_normal     = normals[meshVertexNr];
                    skinnedVertices[globalVert].m_tangent    = (tangents) ? tangents[meshVertexNr] : AZ::Vector4(0.0f, 0.0f, 1.0f, 1.0f);
                    skinnedVertices[globalVert].m_uv         = (uvsA == nullptr) ? AZ::Vector2(0.0f, 0.0f) : uvsA[meshVertexNr];

                    // get the number of influences and iterate through them
                    const size_t numInfluences = skinningInfo->GetNumInfluences(orgVertex);
                    size_t i;
                    for (i = 0; i < numInfluences; ++i)
                    {
                        // get the influence and its weight and set the indices
                        EMotionFX::SkinInfluence* influence                 = skinningInfo->GetInfluence(orgVertex, i);
                        skinnedVertices[globalVert].m_weights[i]     = influence->GetWeight();
                        const size_t boneIndex                      = subMesh->FindBoneIndex(influence->GetNodeNr());
                        skinnedVertices[globalVert].m_boneIndices[i] = static_cast<float>(boneIndex);
                        MCORE_ASSERT(boneIndex != InvalidIndex);
                    }

                    // reset remaining weights and offsets
                    for (size_t a = i; a < 4; ++a)
                    {
                        skinnedVertices[globalVert].m_weights[a]     = 0.0f;
                        skinnedVertices[globalVert].m_boneIndices[a] = 0;
                    }

                    globalVert++;
                }
            }
        }

        // unlock the vertex buffer
        m_vertexBuffers[EMotionFX::Mesh::MESHTYPE_GPU_DEFORMED][lodLevel]->Unlock();
    }