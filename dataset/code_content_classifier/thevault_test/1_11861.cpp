TEST_F(BufferTests, SerializeDeserialize)
    {
        using namespace AZ;

        ExpectedBuffer expectedBuffer;

        Data::Asset<RPI::BufferAsset> bufferAsset = BuildTestBuffer(expectedBuffer);

        SerializeTester<RPI::BufferAsset> tester(GetSerializeContext());
        tester.SerializeOut(bufferAsset.Get());

        Data::Asset<RPI::BufferAsset> serializedBufferAsset = tester.SerializeIn(Data::AssetId(Uuid::CreateRandom()));
        ValidateBufferAsset(serializedBufferAsset.Get(), expectedBuffer);
    }