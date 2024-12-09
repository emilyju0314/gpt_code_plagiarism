TEST_F(BufferTests, Creation)
    {
        using namespace AZ;

        ExpectedBuffer expectedBuffer;

        Data::Asset<RPI::BufferAsset> bufferAsset = BuildTestBuffer(expectedBuffer);
        ValidateBufferAsset(bufferAsset.Get(), expectedBuffer);
    }