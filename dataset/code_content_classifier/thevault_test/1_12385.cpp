void Importer::ResetSharedData(AZStd::vector<SharedData*>& sharedData)
    {
        for (SharedData* data : sharedData)
        {
            data->Reset();
            data->Destroy();
        }
        sharedData.clear();
    }