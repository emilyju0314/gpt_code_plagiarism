TEST_F(NvClothMeshAssetHelper, DISABLED_MeshAssetHelper_ObtainClothMeshNodeInfoWithActor_ReturnsCorrectClothInfo)
    {
        {
            auto actor = AZStd::make_unique<ActorHelper>("actor_test");
            actor->AddJoint(RootNodeName);
            auto meshNode1Index = actor->AddJoint(MeshNode1Name, AZ::Transform::CreateTranslation(AZ::Vector3(3.0f, -2.0f, 0.0f)), RootNodeName);
            auto otherNodeIndex = actor->AddJoint(OtherNodeName, AZ::Transform::CreateTranslation(AZ::Vector3(0.5f, 0.0f, 0.0f)), RootNodeName);
            auto meshNode2Index = actor->AddJoint(MeshNode2Name, AZ::Transform::CreateTranslation(AZ::Vector3(0.2f, 0.6f, 1.0f)), OtherNodeName);
            actor->SetMesh(LodLevel, meshNode1Index, CreateEMotionFXMesh(MeshVertices, MeshIndices, MeshSkinningInfo, MeshUVs/*, MeshClothData*/));
            actor->SetMesh(LodLevel, otherNodeIndex, CreateEMotionFXMesh(MeshVertices, MeshIndices));
            actor->SetMesh(LodLevel, meshNode2Index, CreateEMotionFXMesh(MeshVertices, MeshIndices, MeshSkinningInfo, MeshUVs/*, MeshClothData*/));
            actor->FinishSetup();

            m_actorComponent->SetActorAsset(CreateAssetFromActor(AZStd::move(actor)));
        }

        AZStd::unique_ptr<NvCloth::AssetHelper> assetHelper = NvCloth::AssetHelper::CreateAssetHelper(m_actorComponent->GetEntityId());

        NvCloth::MeshNodeInfo meshNodeInfo;
        NvCloth::MeshClothInfo meshClothInfo;
        bool infoObtained = assetHelper->ObtainClothMeshNodeInfo(MeshNode2Name, meshNodeInfo, meshClothInfo);

        EXPECT_TRUE(infoObtained);

        EXPECT_EQ(meshNodeInfo.m_lodLevel, LodLevel);
        ASSERT_EQ(meshNodeInfo.m_subMeshes.size(), 1);
        EXPECT_EQ(meshNodeInfo.m_subMeshes[0].m_primitiveIndex, 2);
        EXPECT_EQ(meshNodeInfo.m_subMeshes[0].m_verticesFirstIndex, 0);
        EXPECT_EQ(meshNodeInfo.m_subMeshes[0].m_numVertices, MeshVertices.size());
        EXPECT_EQ(meshNodeInfo.m_subMeshes[0].m_indicesFirstIndex, 0);
        EXPECT_EQ(meshNodeInfo.m_subMeshes[0].m_numIndices, MeshIndices.size());

        EXPECT_EQ(meshClothInfo.m_particles.size(), MeshVertices.size());
        EXPECT_EQ(meshClothInfo.m_particles.size(), MeshClothData.size());
        for (size_t i = 0; i < meshClothInfo.m_particles.size(); ++i)
        {
            EXPECT_THAT(meshClothInfo.m_particles[i].GetAsVector3(), IsCloseTolerance(MeshVertices[i], Tolerance));
            EXPECT_NEAR(meshClothInfo.m_particles[i].GetW(), MeshClothData[i].GetR(), ToleranceU8);
        }
        EXPECT_EQ(meshClothInfo.m_indices, MeshIndices);
        EXPECT_THAT(meshClothInfo.m_uvs, ::testing::Pointwise(ContainerIsCloseTolerance(Tolerance), MeshUVs));
        EXPECT_EQ(meshClothInfo.m_motionConstraints.size(), MeshClothData.size());
        for (size_t i = 0; i < meshClothInfo.m_motionConstraints.size(); ++i)
        {
            EXPECT_NEAR(meshClothInfo.m_motionConstraints[i], MeshClothData[i].GetG(), ToleranceU8);
        }
        EXPECT_EQ(meshClothInfo.m_backstopData.size(), MeshClothData.size());
        for (size_t i = 0; i < meshClothInfo.m_backstopData.size(); ++i)
        {
            EXPECT_THAT(meshClothInfo.m_backstopData[i], IsCloseTolerance(AZ::Vector2(MeshClothData[i].GetB() * 2.0f - 1.0f, MeshClothData[i].GetA()), ToleranceU8));
        }
    }