TEST_F(ModelTests, SetMaterialSlotNoBeginNoBeginMesh)
    {
        using namespace AZ;

        RPI::ModelLodAssetCreator creator;

        {
            ErrorMessageFinder messageFinder("Begin() was not called");
            creator.SetMeshMaterialSlot(0);
        }

        creator.Begin(Data::AssetId(AZ::Uuid::CreateRandom()));

        //This should still fail even if we call Begin but not BeginMesh
        {
            ErrorMessageFinder messageFinder("BeginMesh() was not called");
            creator.SetMeshMaterialSlot(0);
        }
    }