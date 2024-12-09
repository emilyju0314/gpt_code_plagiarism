TEST_F(NvClothEditorClothComponent, DISABLED_EditorClothComponent_OnMeshCreatedWithActorWithoutClothMesh_ReturnsMeshNodeListWithNoClothMessage)
    {
        auto editorEntity = CreateInactiveEditorEntity("ClothComponentEditorEntity");
        auto* editorClothComponent = editorEntity->CreateComponent<NvCloth::EditorClothComponent>();
        auto* editorActorComponent = editorEntity->CreateComponent<EMotionFX::Integration::EditorActorComponent>();
        editorEntity->Activate();

        {
            auto actor = AZStd::make_unique<ActorHelper>("actor_test");
            auto jointRootIndex = actor->AddJoint(JointRootName);
            actor->SetMesh(LodLevel, jointRootIndex, CreateEMotionFXMesh(MeshVertices, MeshIndices, {}, MeshUVs));
            actor->FinishSetup();

            editorActorComponent->SetActorAsset(CreateAssetFromActor(AZStd::move(actor)));
        }

        const NvCloth::MeshNodeList& meshNodeList = editorClothComponent->GetMeshNodeList();

        ASSERT_EQ(meshNodeList.size(), 1);
        EXPECT_TRUE(meshNodeList[0] == NvCloth::Internal::StatusMessageNoClothNodes);
    }