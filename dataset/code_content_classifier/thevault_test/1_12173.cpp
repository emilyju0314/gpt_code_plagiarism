TEST_F(NvClothEditorClothComponent, DISABLED_EditorClothComponent_OnMeshCreatedWithActorWithClothMesh_ReturnsValidMeshNodeList)
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

        const NvCloth::MeshNodeList& meshNodeList = editorClothComponent->GetMeshNodeList();

        ASSERT_EQ(meshNodeList.size(), 2);
        EXPECT_TRUE(meshNodeList[0] == NvCloth::Internal::StatusMessageSelectNode);
        EXPECT_TRUE(meshNodeList[1] == MeshNodeName);
    }