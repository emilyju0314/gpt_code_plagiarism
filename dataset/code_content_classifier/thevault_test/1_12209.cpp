void VertexAttributeLayerAbstractData::ResetToOriginalData()
    {
        // if we dont have any original data, there is nothing to do
        if (m_keepOriginals == false)
        {
            return;
        }

        // get the data pointers
        uint8* originalData = (uint8*)GetOriginalData();
        uint8* data         = (uint8*)GetData();

        // copy the original data over the current data
        MCore::MemCopy(data, originalData, CalcTotalDataSizeInBytes(false));
    }