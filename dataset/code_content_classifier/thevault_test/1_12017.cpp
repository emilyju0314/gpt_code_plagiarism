TEST_F(NvClothComponentMesh, DISABLED_ClothComponentMesh_UpdateConfigurationNewMeshNode_ReturnsRenderDataFromNewMeshNode)
    {
        const AZStd::string meshNode2Name = "cloth_node_2";
        
        const AZStd::vector<AZ::Vector3> mesh2Vertices = {{
            AZ::Vector3(-2.3f, 0.0f, 0.0f),
            AZ::Vector3(4.0f, 0.0f, 0.0f),
            AZ::Vector3(0.0f, -1.0f, 0.0f)
        }};

        {
            auto actor = AZStd::make_unique<ActorHelper>("actor_test");
            auto meshNodeIndex = actor->AddJoint(MeshNodeName);
            auto meshNode2Index = actor->AddJoint(meshNode2Name);
            actor->SetMesh(LodLevel, meshNodeIndex, CreateEMotionFXMesh(MeshVertices, MeshIndices, MeshSkinningInfo, MeshUVs/*, MeshClothData*/));
            actor->SetMesh(LodLevel, meshNode2Index, CreateEMotionFXMesh(mesh2Vertices, MeshIndices, MeshSkinningInfo, MeshUVs/*, MeshClothData*/));
            actor->FinishSetup();

            m_actorComponent->SetActorAsset(CreateAssetFromActor(AZStd::move(actor)));
        }

        NvCloth::ClothConfiguration clothConfig;
        clothConfig.m_meshNode = MeshNodeName;

        NvCloth::ClothComponentMesh clothComponentMesh(m_actorComponent->GetEntityId(), clothConfig);

        clothConfig.m_meshNode = meshNode2Name;
        clothComponentMesh.UpdateConfiguration(m_actorComponent->GetEntityId(), clothConfig);

        const auto& renderData = clothComponentMesh.GetRenderData();

        EXPECT_EQ(renderData.m_particles.size(), mesh2Vertices.size());
        EXPECT_EQ(renderData.m_particles.size(), MeshClothData.size());
        for (size_t i = 0; i < renderData.m_particles.size(); ++i)
        {
            EXPECT_THAT(renderData.m_particles[i].GetAsVector3(), IsCloseTolerance(mesh2Vertices[i], Tolerance));
            EXPECT_NEAR(renderData.m_particles[i].GetW(), MeshClothData[i].GetR(), ToleranceU8);
        }
    }