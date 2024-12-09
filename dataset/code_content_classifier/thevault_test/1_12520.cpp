TEST_F(PrefabInstantiateTest, DISABLED_PrefabInstantiate_TripleNestingTemplate_InstantiateSucceeds)
    {
        AZ::Entity* newEntity = CreateEntity("New Entity");
        AzToolsFramework::EditorEntityContextRequestBus::Broadcast(
            &AzToolsFramework::EditorEntityContextRequests::HandleEntitiesAdded, AzToolsFramework::EntityList{newEntity});
        // Build a 3 level deep nested Template
        AZStd::unique_ptr<AzToolsFramework::Prefab::Instance> firstInstance = m_prefabSystemComponent->CreatePrefab({ newEntity }, {}, "test/path1");
        ASSERT_TRUE(firstInstance);

        AZStd::unique_ptr<AzToolsFramework::Prefab::Instance> secondInstance = m_prefabSystemComponent->CreatePrefab({},
            MakeInstanceList(AZStd::move(firstInstance)), "test/path2");
        ASSERT_TRUE(secondInstance);

        AZStd::unique_ptr<AzToolsFramework::Prefab::Instance> thirdInstance = m_prefabSystemComponent->CreatePrefab({},
            MakeInstanceList(AZStd::move(secondInstance)), "test/path3");
        ASSERT_TRUE(thirdInstance);

        //Instantiate it
        AZStd::unique_ptr<AzToolsFramework::Prefab::Instance> fourthInstance =
            m_prefabSystemComponent->InstantiatePrefab(thirdInstance->GetTemplateId());

        ASSERT_TRUE(fourthInstance);

        CompareInstances(*thirdInstance, *fourthInstance, true, false);
    }