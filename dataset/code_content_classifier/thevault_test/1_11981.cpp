TEST_F(ModelTests, SecondMeshAfterEnd)
    {
        using namespace AZ;

        RPI::ModelLodAssetCreator creator;

        creator.Begin(Data::AssetId(AZ::Uuid::CreateRandom()));

        uint32_t indexCount = 36;
        uint32_t vertexCount = 36;

        RHI::BufferViewDescriptor indexBufferViewDescriptor =
            RHI::BufferViewDescriptor::CreateStructured(0, indexCount, sizeof(uint32_t));

        RHI::BufferViewDescriptor vertexBufferViewDescriptor =
            RHI::BufferViewDescriptor::CreateStructured(0, vertexCount, sizeof(float) * 3);

        //Creating this first mesh should work as expected
        {
            AZ::Aabb aabb = AZ::Aabb::CreateCenterRadius(Vector3::CreateZero(), 1.0f);

            creator.BeginMesh();
            creator.SetMeshAabb(AZStd::move(aabb));
            creator.SetMeshMaterialSlot(0);
            creator.SetMeshIndexBuffer({ BuildTestBuffer(indexCount, sizeof(uint32_t)), indexBufferViewDescriptor });
            creator.AddMeshStreamBuffer(GetPositionSemantic(), AZ::Name(), { BuildTestBuffer(vertexCount, sizeof(float) * 3), vertexBufferViewDescriptor });

            creator.EndMesh();
        }

        // This asset creation should be valid
        Data::Asset<RPI::ModelLodAsset> asset;
        EXPECT_TRUE(creator.End(asset));
        EXPECT_TRUE(asset.IsReady());
        EXPECT_NE(asset.Get(), nullptr);

        // This second mesh should fail at every point since we have already
        // called End
        {
            AZ::Aabb aabb = AZ::Aabb::CreateCenterRadius(Vector3::CreateZero(), 1.0f);

            ErrorMessageFinder messageFinder("Begin() was not called", 6);

            creator.BeginMesh();
            creator.SetMeshAabb(AZStd::move(aabb));
            creator.SetMeshMaterialSlot(0);
            creator.SetMeshIndexBuffer({ BuildTestBuffer(indexCount, sizeof(uint32_t)), indexBufferViewDescriptor });
            creator.AddMeshStreamBuffer(GetPositionSemantic(), AZ::Name(), { BuildTestBuffer(vertexCount, sizeof(float) * 3), vertexBufferViewDescriptor });

            creator.EndMesh();
        }
    }