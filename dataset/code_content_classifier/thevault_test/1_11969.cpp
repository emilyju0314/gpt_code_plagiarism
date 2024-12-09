TEST_F(ModelTests, SetNameNoBegin)
    {
        using namespace AZ;

        RPI::ModelAssetCreator creator;

        ErrorMessageFinder messageFinder("Begin() was not called");

        creator.SetName("TestName");
    }