TEST_F(ModelTests, BeginMeshNoBegin)
    {
        using namespace AZ;

        ErrorMessageFinder messageFinder("Begin() was not called");

        RPI::ModelLodAssetCreator creator;
        creator.BeginMesh();
    }