TEST_F(ModelTests, SetIndexBufferNoBeginNoBeginMesh)
    {
        using namespace AZ;

        RPI::ModelLodAssetCreator creator;

        const uint32_t indexCount = 36;
        const uint32_t indexSize = sizeof(uint32_t);

        RHI::BufferViewDescriptor validIndexBufferViewDescriptor =
            RHI::BufferViewDescriptor::CreateStructured(0, indexCount, indexSize);

        Data::Asset<RPI::BufferAsset> validIndexBuffer = BuildTestBuffer(indexCount, indexSize);
        ASSERT_TRUE(validIndexBuffer.Get() != nullptr);

        {
            ErrorMessageFinder messageFinder("Begin() was not called");
            creator.SetMeshIndexBuffer({ AZStd::move(validIndexBuffer), validIndexBufferViewDescriptor });
        }

        creator.Begin(Data::AssetId(AZ::Uuid::CreateRandom()));

        //This should still fail even if we call Begin but not BeginMesh
        validIndexBuffer = BuildTestBuffer(indexCount, indexSize);
        ASSERT_TRUE(validIndexBuffer.Get() != nullptr);

        {
            ErrorMessageFinder messageFinder("BeginMesh() was not called");
            creator.SetMeshIndexBuffer({ AZStd::move(validIndexBuffer), validIndexBufferViewDescriptor });
        }
    }