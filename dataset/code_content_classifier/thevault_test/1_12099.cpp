TEST_F(PhysXEditorFixture, DISABLED_EditorShapeColliderComponent_PolygonPrismForceRegion_AppliesForceAtRuntime)
    {
        // create an editor entity with shape collider, polygon prism shape and force region components
        EntityPtr forceRegionEditorEntity = CreateInactiveEditorEntity("ShapeColliderComponentEditorEntity");
        auto* shapeColliderComponent = forceRegionEditorEntity->CreateComponent<PhysX::EditorShapeColliderComponent>();
        SetTrigger(shapeColliderComponent, true);
        forceRegionEditorEntity->CreateComponent(LmbrCentral::EditorPolygonPrismShapeComponentTypeId);
        forceRegionEditorEntity->CreateComponent<PhysX::EditorForceRegionComponent>();

        // suppress the shape collider error that will be raised because the polygon prism vertices have not been set yet
        UnitTest::ErrorHandler polygonPrismErrorHandler("Invalid polygon prism");
        forceRegionEditorEntity->Activate();

        // modify the geometry of the polygon prism
        TestData testData;
        SetPolygonPrismVertices(forceRegionEditorEntity->GetId(), testData.polygonHShape);
        SetPolygonPrismHeight(forceRegionEditorEntity->GetId(), 2.0f);

        EntityPtr forceRegionGameEntity = CreateActiveGameEntityFromEditorEntity(forceRegionEditorEntity.get());

        // add a force to the force region
        PhysX::ForceRegionRequestBus::Event(forceRegionGameEntity->GetId(),
            &PhysX::ForceRegionRequests::AddForceWorldSpace, AZ::Vector3::CreateAxisX(), 100.0f);

        const AZ::Vector3 boxDimensions(0.5f, 0.5f, 0.5f);
        // create one box over the centre of the polygon prism
        const AZ::Vector3 box1Position(1.5f, 1.5f, 3.0f);
        // create another box over one of the notches in the H
        const AZ::Vector3 box2Position(1.5f, 0.5f, 3.0f);
        EntityPtr rigidBodyGameEntity1 = CreateRigidBox(boxDimensions, box1Position);
        EntityPtr rigidBodyGameEntity2 = CreateRigidBox(boxDimensions, box2Position);

        PhysX::TestUtils::UpdateScene(m_defaultScene, AzPhysics::SystemConfiguration::DefaultFixedTimestep, 100);

        // the first rigid body should have been moved in the positive x direction by the force region
        EXPECT_TRUE(rigidBodyGameEntity1->GetTransform()->GetWorldTranslation().GetX() > box1Position.GetX() + AZ::Constants::FloatEpsilon);
        // the second rigid body should not have entered the force region and so its X position should not have been affected
        EXPECT_NEAR(rigidBodyGameEntity2->GetTransform()->GetWorldTranslation().GetX(), box2Position.GetX(), 1e-3f);
    }