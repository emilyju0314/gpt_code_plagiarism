void GLActor::FillIndexBuffers(size_t lodLevel)
    {
        // initialize the index buffers
        uint32* staticIndices   = nullptr;
        uint32* dynamicIndices  = nullptr;
        uint32* skinnedIndices  = nullptr;

        // lock the index buffers
        if (m_indexBuffers[EMotionFX::Mesh::MESHTYPE_STATIC][lodLevel])
        {
            staticIndices = (uint32*)m_indexBuffers[EMotionFX::Mesh::MESHTYPE_STATIC][lodLevel]->Lock(LOCK_WRITEONLY);
        }
        if (m_indexBuffers[EMotionFX::Mesh::MESHTYPE_CPU_DEFORMED][lodLevel])
        {
            dynamicIndices = (uint32*)m_indexBuffers[EMotionFX::Mesh::MESHTYPE_CPU_DEFORMED][lodLevel]->Lock(LOCK_WRITEONLY);
        }
        if (m_indexBuffers[EMotionFX::Mesh::MESHTYPE_GPU_DEFORMED][lodLevel])
        {
            skinnedIndices = (uint32*)m_indexBuffers[EMotionFX::Mesh::MESHTYPE_GPU_DEFORMED][lodLevel]->Lock(LOCK_WRITEONLY);
        }

        //if (staticIndices == nullptr || dynamicIndices == nullptr || skinnedIndices == nullptr)
        if ((m_indexBuffers[EMotionFX::Mesh::MESHTYPE_STATIC][lodLevel] && staticIndices == nullptr) ||
            (m_indexBuffers[EMotionFX::Mesh::MESHTYPE_CPU_DEFORMED][lodLevel] && dynamicIndices == nullptr) ||
            (m_indexBuffers[EMotionFX::Mesh::MESHTYPE_GPU_DEFORMED][lodLevel] && skinnedIndices == nullptr))
        {
            MCore::LogWarning("[OpenGL] Cannot lock index buffers in GLActor::FillIndexBuffers.");
            return;
        }

        // the total number of vertices
        uint32 totalNumStaticIndices    = 0;
        uint32 totalNumDynamicIndices   = 0;
        uint32 totalNumSkinnedIndices   = 0;
        uint32 dynamicOffset            = 0;
        uint32 staticOffset             = 0;
        uint32 gpuSkinnedOffset         = 0;

        EMotionFX::Skeleton* skeleton = m_actor->GetSkeleton();

        // get the number of nodes and iterate through them
        const size_t numNodes = m_actor->GetNumNodes();
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

            // get the mesh type and the indices
            uint32*                     indices     = mesh->GetIndices();
            uint8*                      vertCounts  = mesh->GetPolygonVertexCounts();
            EMotionFX::Mesh::EMeshType  meshType    = ClassifyMeshType(node, mesh, lodLevel);

            // NOTE: this method triangulates polygons when needed internally
            switch (meshType)
            {
            case EMotionFX::Mesh::MESHTYPE_CPU_DEFORMED:
            {
                uint32 polyStartIndex = 0;
                const uint32 numPolys = mesh->GetNumPolygons();
                for (uint32 p = 0; p < numPolys; ++p)
                {
                    const uint32 numPolyVerts = vertCounts[p];
                    for (uint32 v = 2; v < numPolyVerts; v++)
                    {
                        dynamicIndices[totalNumDynamicIndices++] = indices[polyStartIndex]          + dynamicOffset;
                        dynamicIndices[totalNumDynamicIndices++] = indices[polyStartIndex + v - 1]      + dynamicOffset;
                        dynamicIndices[totalNumDynamicIndices++] = indices[polyStartIndex + v]  + dynamicOffset;
                    }
                    polyStartIndex += numPolyVerts;
                }

                dynamicOffset += mesh->GetNumVertices();
                break;
            }

            case EMotionFX::Mesh::MESHTYPE_STATIC:
            {
                uint32 polyStartIndex = 0;
                const uint32 numPolys = mesh->GetNumPolygons();
                for (uint32 p = 0; p < numPolys; ++p)
                {
                    const uint32 numPolyVerts = vertCounts[p];
                    for (uint32 v = 2; v < numPolyVerts; v++)
                    {
                        staticIndices[totalNumStaticIndices++] = indices[polyStartIndex]            + staticOffset;
                        staticIndices[totalNumStaticIndices++] = indices[polyStartIndex + v - 1]        + staticOffset;
                        staticIndices[totalNumStaticIndices++] = indices[polyStartIndex + v]    + staticOffset;
                    }
                    polyStartIndex += numPolyVerts;
                }

                staticOffset += mesh->GetNumVertices();
                break;
            }

            case EMotionFX::Mesh::MESHTYPE_GPU_DEFORMED:
            {
                uint32 polyStartIndex = 0;
                const uint32 numPolys = mesh->GetNumPolygons();
                for (uint32 p = 0; p < numPolys; ++p)
                {
                    const uint32 numPolyVerts = vertCounts[p];
                    for (uint32 v = 2; v < numPolyVerts; v++)
                    {
                        skinnedIndices[totalNumSkinnedIndices++] = indices[polyStartIndex]          + gpuSkinnedOffset;
                        skinnedIndices[totalNumSkinnedIndices++] = indices[polyStartIndex + v - 1]      + gpuSkinnedOffset;
                        skinnedIndices[totalNumSkinnedIndices++] = indices[polyStartIndex + v]  + gpuSkinnedOffset;
                    }
                    polyStartIndex += numPolyVerts;
                }

                gpuSkinnedOffset += mesh->GetNumVertices();
                break;
            }
            }
        }

        // unlock the buffers
        if (staticIndices)
        {
            m_indexBuffers[EMotionFX::Mesh::MESHTYPE_STATIC][lodLevel]->Unlock();
        }
        if (dynamicIndices)
        {
            m_indexBuffers[EMotionFX::Mesh::MESHTYPE_CPU_DEFORMED][lodLevel]->Unlock();
        }
        if (skinnedIndices)
        {
            m_indexBuffers[EMotionFX::Mesh::MESHTYPE_GPU_DEFORMED][lodLevel]->Unlock();
        }
    }