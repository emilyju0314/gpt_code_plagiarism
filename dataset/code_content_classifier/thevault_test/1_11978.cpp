TEST_F(ModelTests, AddStreamBufferNoBeginNoBeginMesh)
    {
        using namespace AZ;

        RPI::ModelLodAssetCreator creator;

        const uint32_t vertexCount = 36;
        const uint32_t vertexSize = sizeof(float) * 3;

        RHI::BufferViewDescriptor validStreamBufferViewDescriptor =
            RHI::BufferViewDescriptor::CreateStructured(0, vertexCount, vertexSize);

        Data::Asset<RPI::BufferAsset> validStreamBuffer = BuildTestBuffer(vertexCount, vertexSize);

        {
            ErrorMessageFinder messageFinder("Begin() was not called");
            creator.AddMeshStreamBuffer(GetPositionSemantic(), AZ::Name(), { AZStd::move(validStreamBuffer), validStreamBufferViewDescriptor });
        }

        creator.Begin(Data::AssetId(AZ::Uuid::CreateRandom()));

        //This should still fail even if we call Begin but not BeginMesh
        validStreamBuffer = BuildTestBuffer(vertexCount, vertexSize);

        {
            ErrorMessageFinder messageFinder("BeginMesh() was not called");
            creator.AddMeshStreamBuffer(GetPositionSemantic(), AZ::Name(), { AZStd::move(validStreamBuffer), validStreamBufferViewDescriptor });
        }
    }