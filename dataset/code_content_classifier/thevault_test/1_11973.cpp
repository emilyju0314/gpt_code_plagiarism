TEST_F(ModelTests, AddLodStreamBufferNoBegin)
    {
        using namespace AZ;

        Data::Asset<RPI::BufferAsset> validStreamBuffer = BuildTestBuffer(10, sizeof(float) * 3);

        ErrorMessageFinder messageFinder("Begin() was not called");

        RPI::ModelLodAssetCreator creator;
        creator.AddLodStreamBuffer(validStreamBuffer);
    }