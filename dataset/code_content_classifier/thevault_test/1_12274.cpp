TEST_F(SliceStabilityTest, ReParent_NestedSliceCreatedFromSliceInstanceChild_SliceHierarchyRemainsSame_FT)
    {
        AUTO_RESULT_IF_SETTING_TRUE(UnitTest::prefabSystemSetting, true)

        AzToolsFramework::EntityIdList instance1Entities;
        AZ::EntityId instance1Root = CreateEditorEntity("Slice1Root", instance1Entities);
        ASSERT_TRUE(instance1Root.IsValid());

        AZ::EntityId instance1Child = CreateEditorEntity("Slice1Child", instance1Entities, instance1Root);
        ASSERT_TRUE(instance1Child.IsValid());

        EXPECT_TRUE(m_validator.Capture(instance1Entities));

        AZ::SliceComponent::SliceInstanceAddress slice1InstanceAddress;
        AZ::Data::AssetId slice1Asset = CreateSlice("Slice1", instance1Entities, slice1InstanceAddress);
        ASSERT_TRUE(slice1Asset.IsValid());

        EXPECT_TRUE(m_validator.Compare(slice1InstanceAddress));
        m_validator.Reset();

        AzToolsFramework::EntityIdList nestedSliceEntities = AzToolsFramework::EntityIdList{ instance1Child };
        EXPECT_TRUE(m_validator.Capture(nestedSliceEntities));

        AZ::SliceComponent::SliceInstanceAddress nestedSliceInstanceAddress;
        AZ::Data::AssetId nestedSliceAsset =
            CreateSlice("NestedSlice", nestedSliceEntities, nestedSliceInstanceAddress);
        ASSERT_TRUE(nestedSliceAsset.IsValid());
        EXPECT_TRUE(m_validator.Compare(nestedSliceInstanceAddress));

        const AZ::SliceComponent::EntityList nestedSliceInstanceEntities =
            nestedSliceInstanceAddress.GetInstance()->GetInstantiated()->m_entities;
        EXPECT_EQ(nestedSliceInstanceEntities.size(), 1);

        AZ::EntityId nestedSliceRootParentId;
        AZ::TransformBus::EventResult(nestedSliceRootParentId, nestedSliceInstanceEntities[0]->GetId(), &AZ::TransformBus::Events::GetParentId);

        // Validate that the parent of nested slice root is the same as the parent of the instance it was created from.
        EXPECT_EQ(instance1Root, nestedSliceRootParentId);
    }