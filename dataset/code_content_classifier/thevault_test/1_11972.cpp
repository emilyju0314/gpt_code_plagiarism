TEST_F(ModelTests, SetLodIndexBufferNoBegin)
    {
        using namespace AZ;

        Data::Asset<RPI::BufferAsset> validIndexBuffer = BuildTestBuffer(10, sizeof(uint32_t));

        ErrorMessageFinder messageFinder("Begin() was not called");

        RPI::ModelLodAssetCreator creator;
        creator.SetLodIndexBuffer(validIndexBuffer);
    }