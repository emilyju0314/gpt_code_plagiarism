void Importer::AddSharedData(AZStd::vector<SharedData*>& sharedData, SharedData* data)
    {
        MCORE_ASSERT(data);
        sharedData.emplace_back(data);
    }