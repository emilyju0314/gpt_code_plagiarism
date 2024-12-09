void Actor::FindMostInfluencedMeshPoints(const Node* node, AZStd::vector<AZ::Vector3>& outPoints) const
    {
        outPoints.clear();

        const size_t geomLODLevel = 0;
        const size_t numNodes = m_skeleton->GetNumNodes();

        for (size_t nodeIndex = 0; nodeIndex < numNodes; nodeIndex++)
        {
            // check if this node has a mesh, if not we can skip it
            Mesh* mesh = GetMesh(geomLODLevel, nodeIndex);
            if (mesh == nullptr)
            {
                continue;
            }

            // check if the mesh is skinned, if not, we don't need to do anything
            SkinningInfoVertexAttributeLayer* layer = (SkinningInfoVertexAttributeLayer*)mesh->FindSharedVertexAttributeLayer(SkinningInfoVertexAttributeLayer::TYPE_ID);
            if (layer == nullptr)
            {
                continue;
            }

            // get shortcuts to the original vertex numbers
            const uint32* orgVertices = (uint32*)mesh->FindOriginalVertexData(Mesh::ATTRIB_ORGVTXNUMBERS);
            AZ::Vector3* positions = (AZ::Vector3*)mesh->FindVertexData(EMotionFX::Mesh::ATTRIB_POSITIONS);

            // for all submeshes
            const size_t numSubMeshes = mesh->GetNumSubMeshes();
            for (size_t subMeshIndex = 0; subMeshIndex < numSubMeshes; ++subMeshIndex)
            {
                SubMesh* subMesh = mesh->GetSubMesh(subMeshIndex);

                // for all vertices in the submesh
                const uint32 startVertex = subMesh->GetStartVertex();
                const uint32 numVertices = subMesh->GetNumVertices();
                for (uint32 vertexIndex = 0; vertexIndex < numVertices; ++vertexIndex)
                {
                    const uint32 orgVertex = orgVertices[startVertex + vertexIndex];

                    // for all skinning influences of the vertex
                    const size_t numInfluences = layer->GetNumInfluences(orgVertex);
                    float maxWeight = 0.0f;
                    size_t maxWeightNodeIndex = 0;
                    for (size_t i = 0; i < numInfluences; ++i)
                    {
                        SkinInfluence* influence = layer->GetInfluence(orgVertex, i);
                        float weight = influence->GetWeight();
                        if (weight > maxWeight)
                        {
                            maxWeight = weight;
                            maxWeightNodeIndex = influence->GetNodeNr();
                        }
                    } // for all influences

                    if (maxWeightNodeIndex == node->GetNodeIndex())
                    {
                        outPoints.push_back(positions[vertexIndex + startVertex]);
                    }
                } // for all verts
            } // for all submeshes
        }
    }