void Actor::MakeGeomLODsCompatibleWithSkeletalLODs()
    {
        const AZStd::vector<LODLevel>& lodLevels = m_meshLodData.m_lodLevels;

        // for all geometry lod levels
        const size_t numGeomLODs = lodLevels.size();
        for (size_t geomLod = 0; geomLod < numGeomLODs; ++geomLod)
        {
            // for all nodes
            const size_t numNodes = m_skeleton->GetNumNodes();
            for (size_t n = 0; n < numNodes; ++n)
            {
                Node* node = m_skeleton->GetNode(n);

                // check if this node has a mesh, if not we can skip it
                Mesh* mesh = GetMesh(static_cast<uint32>(geomLod), n);
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

                // for all submeshes
                const size_t numSubMeshes = mesh->GetNumSubMeshes();
                for (size_t s = 0; s < numSubMeshes; ++s)
                {
                    SubMesh* subMesh = mesh->GetSubMesh(s);

                    // for all vertices in the submesh
                    const uint32 startVertex = subMesh->GetStartVertex();
                    const uint32 numVertices = subMesh->GetNumVertices();
                    for (uint32 v = 0; v < numVertices; ++v)
                    {
                        const uint32 vertexIndex    = startVertex + v;
                        const uint32 orgVertex      = orgVertices[vertexIndex];

                        // for all skinning influences of the vertex
                        const size_t numInfluences = layer->GetNumInfluences(orgVertex);
                        for (size_t i = 0; i < numInfluences; ++i)
                        {
                            // if the bone is disabled
                            SkinInfluence* influence = layer->GetInfluence(orgVertex, i);
                            if (m_skeleton->GetNode(influence->GetNodeNr())->GetSkeletalLODStatus(static_cast<uint32>(geomLod)) == false)
                            {
                                // find the first parent bone that is enabled in this LOD
                                const size_t newNodeIndex = FindFirstActiveParentBone(geomLod, influence->GetNodeNr());
                                if (newNodeIndex == InvalidIndex)
                                {
                                    MCore::LogWarning("EMotionFX::Actor::MakeGeomLODsCompatibleWithSkeletalLODs() - Failed to find an enabled parent for node '%s' in skeletal LOD %d of actor '%s' (0x%x)", node->GetName(), geomLod, GetFileName(), this);
                                    continue;
                                }

                                // set the new node index
                                influence->SetNodeNr(static_cast<uint16>(newNodeIndex));
                            }
                        } // for all influences

                        // optimize the influences
                        // if they all use the same bone, just make one influence of it with weight 1.0
                        for (uint32 x = 0; x < numVertices; ++x)
                        {
                            layer->CollapseInfluences(orgVertices[startVertex + x]);
                        }
                    } // for all verts

                    // clear the bones array
                    subMesh->ReinitBonesArray(layer);
                } // for all submeshes

                // reinit the mesh deformer stacks
                MeshDeformerStack* stack = GetMeshDeformerStack(static_cast<uint32>(geomLod), node->GetNodeIndex());
                if (stack)
                {
                    stack->ReinitializeDeformers(this, node, static_cast<uint32>(geomLod));
                }
            } // for all nodes
        }
    }