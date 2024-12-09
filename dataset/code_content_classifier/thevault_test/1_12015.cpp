TEST_F(NvClothComponentMesh, DISABLED_ClothComponentMesh_InitWithEntityActor_ReturnsValidRenderData)
    {
        {
            auto actor = AZStd::make_unique<ActorHelper>("actor_test");
            auto meshNodeIndex = actor->AddJoint(MeshNodeName);
            actor->SetMesh(LodLevel, meshNodeIndex, CreateEMotionFXMesh(MeshVertices, MeshIndices, MeshSkinningInfo, MeshUVs/*, MeshClothData*/));
            actor->FinishSetup();

            m_actorComponent->SetActorAsset(CreateAssetFromActor(AZStd::move(actor)));
        }

        NvCloth::ClothConfiguration clothConfig;
        clothConfig.m_meshNode = MeshNodeName;

        NvCloth::ClothComponentMesh clothComponentMesh(m_actorComponent->GetEntityId(), clothConfig);

        const auto& renderData = clothComponentMesh.GetRenderData();

        EXPECT_EQ(renderData.m_particles.size(), MeshVertices.size());
        EXPECT_EQ(renderData.m_particles.size(), MeshClothData.size());
        for (size_t i = 0; i < renderData.m_particles.size(); ++i)
        {
            EXPECT_THAT(renderData.m_particles[i].GetAsVector3(), IsCloseTolerance(MeshVertices[i], Tolerance));
            EXPECT_NEAR(renderData.m_particles[i].GetW(), MeshClothData[i].GetR(), ToleranceU8);
        }

        EXPECT_THAT(renderData.m_tangents, ::testing::Each(IsCloseTolerance(AZ::Vector3::CreateAxisX(), Tolerance)));
        EXPECT_THAT(renderData.m_bitangents, ::testing::Each(IsCloseTolerance(AZ::Vector3::CreateAxisY(), Tolerance)));
        EXPECT_THAT(renderData.m_normals, ::testing::Each(IsCloseTolerance(AZ::Vector3::CreateAxisZ(), Tolerance)));
    }