TEST_F(ModelTests, AddLodNoBegin)
    {
        using namespace AZ;

        RPI::ModelAssetCreator creator;

        //Build a valid lod
        ExpectedLod expectedLod;
        Data::Asset<RPI::ModelLodAsset> lod = BuildTestLod(0, 1, expectedLod);

        ErrorMessageFinder messageFinder("Begin() was not called");

        creator.AddLodAsset(AZStd::move(lod));
    }