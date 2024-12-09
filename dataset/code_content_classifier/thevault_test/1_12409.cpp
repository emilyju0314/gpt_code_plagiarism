TEST_F(NvClothMeshAssetHelper, DISABLED_MeshAssetHelper_GatherClothMeshNodesWithActor_ReturnsCorrectMeshNodeList)
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

        NvCloth::MeshNodeList meshNodes;
        assetHelper->GatherClothMeshNodes(meshNodes);

        ASSERT_EQ(meshNodes.size(), 2);
        EXPECT_TRUE(meshNodes[0] == MeshNode1Name);
        EXPECT_TRUE(meshNodes[1] == MeshNode2Name);
    }