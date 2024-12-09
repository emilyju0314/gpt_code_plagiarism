TEST_F(NvClothEditorClothComponent, DISABLED_EditorClothComponent_OnMeshCreatedWithActorWithBackstop_ReturnsValidMeshNodesWithBackstopData)
    {
        auto editorEntity = CreateInactiveEditorEntity("ClothComponentEditorEntity");
        auto* editorClothComponent = editorEntity->CreateComponent<NvCloth::EditorClothComponent>();
        auto* editorActorComponent = editorEntity->CreateComponent<EMotionFX::Integration::EditorActorComponent>();
        editorEntity->Activate();

        {
            auto actor = AZStd::make_unique<ActorHelper>("actor_test");
            actor->AddJoint(JointRootName);
            auto meshNodeIndex = actor->AddJoint(MeshNodeName, AZ::Transform::CreateIdentity(), JointRootName);
            actor->SetMesh(LodLevel, meshNodeIndex, CreateEMotionFXMesh(MeshVertices, MeshIndices, {}, MeshUVs/*, MeshClothData*/));
            actor->FinishSetup();

            editorActorComponent->SetActorAsset(CreateAssetFromActor(AZStd::move(actor)));
        }

        const auto& meshNodesWithBackstopData = editorClothComponent->GetMeshNodesWithBackstopData();

        EXPECT_EQ(meshNodesWithBackstopData.size(), 1);
        EXPECT_TRUE(meshNodesWithBackstopData.find(MeshNodeName) != meshNodesWithBackstopData.end());
    }