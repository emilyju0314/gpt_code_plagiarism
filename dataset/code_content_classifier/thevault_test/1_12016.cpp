TEST_F(NvClothComponentMesh, DISABLED_ClothComponentMesh_UpdateConfigurationDifferentEntity_ReturnsRenderDataFromNewEntity)
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

        const AZStd::vector<AZ::Vector3> newMeshVertices = {{
            AZ::Vector3(-2.3f, 0.0f, 0.0f),
            AZ::Vector3(4.0f, 0.0f, 0.0f),
            AZ::Vector3(0.0f, -1.0f, 0.0f)
        }};

        auto newEntity = AZStd::make_unique<AZ::Entity>();
        newEntity->CreateComponent<AzFramework::TransformComponent>();
        auto* newActorComponent = newEntity->CreateComponent<EMotionFX::Integration::ActorComponent>();
        newEntity->Init();
        newEntity->Activate();
        {
            auto actor = AZStd::make_unique<ActorHelper>("actor_test2");
            auto meshNodeIndex = actor->AddJoint(MeshNodeName);
            actor->SetMesh(LodLevel, meshNodeIndex, CreateEMotionFXMesh(newMeshVertices, MeshIndices, MeshSkinningInfo, MeshUVs/*, MeshClothData*/));
            actor->FinishSetup();

            newActorComponent->SetActorAsset(CreateAssetFromActor(AZStd::move(actor)));
        }

        clothComponentMesh.UpdateConfiguration(newActorComponent->GetEntityId(), clothConfig);

        const auto& renderData = clothComponentMesh.GetRenderData();

        EXPECT_EQ(renderData.m_particles.size(), newMeshVertices.size());
        EXPECT_EQ(renderData.m_particles.size(), MeshClothData.size());
        for (size_t i = 0; i < renderData.m_particles.size(); ++i)
        {
            EXPECT_THAT(renderData.m_particles[i].GetAsVector3(), IsCloseTolerance(newMeshVertices[i], Tolerance));
            EXPECT_NEAR(renderData.m_particles[i].GetW(), MeshClothData[i].GetR(), ToleranceU8);
        }
    }