TEST_F(NvClothComponentMesh, DISABLED_ClothComponentMesh_ModifyMesh_RenderMeshIsUpdated)
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

        // Ticking Cloth System updates all its solvers
        for (size_t i = 0; i < 300.0f; ++i)
        {
            const float deltaTimeSim = 1.0f / 60.0f;
            AZ::TickBus::Broadcast(&AZ::TickEvents::OnTick,
                deltaTimeSim,
                AZ::ScriptTimePoint(AZStd::chrono::system_clock::now()));
        }

        /*
        CryRenderMeshStub renderMesh(MeshVertices);

        LmbrCentral::MeshModificationNotificationBus::Event(
            m_actorComponent->GetEntityId(),
            &LmbrCentral::MeshModificationNotificationBus::Events::ModifyMesh,
            LodLevel,
            0,
            &renderMesh);

        const AZStd::vector<NvCloth::SimParticleFormat>& clothParticles = clothComponentMesh.GetRenderData().m_particles;
        const AZStd::vector<Vec3>& renderMeshPositions = renderMesh.m_positions;

        EXPECT_EQ(renderMeshPositions.size(), clothParticles.size());
        for (size_t i = 0; i < renderMeshPositions.size(); ++i)
        {
            EXPECT_THAT(LYVec3ToAZVec3(renderMeshPositions[i]), IsCloseTolerance(clothParticles[i].GetAsVector3(), Tolerance));
        }
        */
    }