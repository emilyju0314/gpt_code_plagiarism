TEST_F(ModelTests, SetAabbNoBeginNoBeginMesh)
    {
        using namespace AZ;

        RPI::ModelLodAssetCreator creator;

        AZ::Aabb aabb = AZ::Aabb::CreateCenterRadius(AZ::Vector3::CreateZero(), 1.0f);
        ASSERT_TRUE(aabb.IsValid());

        {
            ErrorMessageFinder messageFinder("Begin() was not called");
            AZ::Aabb testAabb = aabb;
            creator.SetMeshAabb(AZStd::move(testAabb));
        }

        creator.Begin(Data::AssetId(AZ::Uuid::CreateRandom()));

        //This should still fail even if we call Begin but not BeginMesh
        {
            ErrorMessageFinder messageFinder("BeginMesh() was not called");
            AZ::Aabb testAabb = aabb;
            creator.SetMeshAabb(AZStd::move(testAabb));
        }
    }