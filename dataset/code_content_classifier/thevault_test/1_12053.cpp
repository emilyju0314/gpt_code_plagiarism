TEST_F(HierarchyTests, On_Client_EntityReplicator_Activates_AfterParent)
    {
        AZStd::unique_ptr<AZ::Entity> childEntity = AZStd::make_unique<AZ::Entity>();
        CreateEntityWithChildHierarchy(childEntity);
        SetupEntity(childEntity, NetEntityId{ 2 }, NetEntityRole::Client);

        // we need a parent-id value to be present in NetworkTransformComponent (which is in client mode and doesn't have a controller)
        SetParentIdOnNetworkTransform(childEntity, NetEntityId{ 1 });
        SetHierarchyRootFieldOnNetworkHierarchyChild<NetworkHierarchyChildComponent>(childEntity, NetEntityId{ 1 });

        // Create an entity replicator for the child entity
        const NetworkEntityHandle childHandle(childEntity.get(), m_networkEntityTracker.get());
        EntityReplicator childEntityReplicator(*m_entityReplicationManager, m_mockConnection.get(), NetEntityRole::Authority, childHandle);
        childEntityReplicator.Initialize(childHandle);

        // Now let's create a parent entity and activate it
        AZStd::unique_ptr<AZ::Entity> parentEntity = AZStd::make_unique<AZ::Entity>();
        CreateEntityWithRootHierarchy(parentEntity);
        SetupEntity(parentEntity, NetEntityId{ 1 }, NetEntityRole::Client);

        // Create an entity replicator for the parent entity
        const NetworkEntityHandle parentHandle(parentEntity.get(), m_networkEntityTracker.get());
        ON_CALL(*m_mockNetworkEntityManager, GetEntity(_)).WillByDefault(Return(parentHandle));
        EntityReplicator parentEntityReplicator(*m_entityReplicationManager, m_mockConnection.get(), NetEntityRole::Authority, parentHandle);
        parentEntityReplicator.Initialize(parentHandle);

        parentEntity->Activate();

        // The child should be ready to be activated
        EXPECT_EQ(childEntityReplicator.IsReadyToActivate(), true);

        StopEntity(parentEntity);

        parentEntity->Deactivate();
    }