TEST_F(AssetManagerTest, AssetSerializerAssetReferenceTest)
    {
        auto assetId = AssetId("{3E971FD2-DB5F-4617-9061-CCD3606124D0}", 0);
        
        SerializeContext context;
        AssetWithAssetReference::Reflect(context);
        char memBuffer[4096];
        AZ::IO::MemoryStream memStream(memBuffer, AZ_ARRAY_SIZE(memBuffer), 0);


        // generate the data stream for the object contains a reference of asset
        AssetWithAssetReference toSave;
        {
            Asset<AssetWithCustomData> assetRef;
            ASSERT_TRUE(assetRef.Create(assetId, AZ::Data::AssetLoadBehavior::PreLoad, false));
            toSave.m_asset = assetRef;
        }
        Utils::SaveObjectToStream(memStream, DataStream::StreamType::ST_BINARY, &toSave, &context);
        toSave.m_asset.Release();

        // Unregister asset handler for AssetWithCustomData
        AssetManager::Instance().UnregisterHandler(m_assetHandlerAndCatalog);

        Utils::FilterDescriptor desc;
        AssetWithAssetReference toRead;

        // return true if loading with none filter or ignore unknown classes filter
        memStream.Seek(0, AZ::IO::GenericStream::ST_SEEK_BEGIN);
        AZ_TEST_START_TRACE_SUPPRESSION;
        desc.m_flags = 0;
        ASSERT_TRUE(Utils::LoadObjectFromStreamInPlace(memStream, toRead, &context, desc));
        // LoadObjectFromStreamInPlace generates two errors. One is can't find the handler. Another one is can't load referenced asset.
        AZ_TEST_STOP_TRACE_SUPPRESSION(2);

        // return true if loading with ignore unknown classes filter
        memStream.Seek(0, AZ::IO::GenericStream::ST_SEEK_BEGIN);
        AZ_TEST_START_TRACE_SUPPRESSION;
        desc.m_flags = ObjectStream::FILTERFLAG_IGNORE_UNKNOWN_CLASSES;
        ASSERT_TRUE(Utils::LoadObjectFromStreamInPlace(memStream, toRead, &context, desc));
        // LoadObjectFromStreamInPlace generates two errors. One is can't find the handler. Another one is can't load referenced asset.
        AZ_TEST_STOP_TRACE_SUPPRESSION(2);

        // return false if loading with strict filter
        memStream.Seek(0, AZ::IO::GenericStream::ST_SEEK_BEGIN);
        AZ_TEST_START_TRACE_SUPPRESSION;
        desc.m_flags = ObjectStream::FILTERFLAG_STRICT;
        ASSERT_FALSE(Utils::LoadObjectFromStreamInPlace(memStream, toRead, &context, desc));
        // LoadObjectFromStreamInPlace generates two errors. One is can't find the handler. Another one is can't load referenced asset.
        AZ_TEST_STOP_TRACE_SUPPRESSION(2);
    }