void VertexAttributeLayerAbstractData::RemoveAttributes(uint32 startAttributeNr, uint32 endAttributeNr)
    {
        // perform some checks on the input data
        MCORE_ASSERT(startAttributeNr < m_numAttributes);
        MCORE_ASSERT(endAttributeNr < m_numAttributes);

        // Store the original number of bytes for the reallocation
        const size_t numOriginalBytes = CalcTotalDataSizeInBytes(m_keepOriginals);

        // make sure the start attribute number is lower than the end
        uint32 start = startAttributeNr;
        uint32 end   = endAttributeNr;
        if (start > end)
        {
            uint32 temp = start;
            start = end;
            end = temp;
        }

        //------------
        // if there isn't anything to remove, quit
        const uint32 numAttribsToRemove = (end - start) + 1; // +1 because we remove the last one as well
        if (numAttribsToRemove == 0)
        {
            return;
        }

        // remove the attributes from the current data
        const uint32 numBytesToMove = (m_numAttributes - end - 1) * m_attribSizeInBytes;
        if (numBytesToMove > 0)
        {
            MCore::MemMove(m_data + start * m_attribSizeInBytes, m_data + (end + 1) * m_attribSizeInBytes, numBytesToMove);
        }

        // remove the attributes from the original data
        if (m_keepOriginals)
        {
            // remove them from the original data
            uint8* orgData = (uint8*)GetOriginalData();

            if (numBytesToMove > 0)
            {
                MCore::MemMove(orgData + start * m_attribSizeInBytes, orgData + (end + 1) * m_attribSizeInBytes, numBytesToMove);
            }

            // remove the created gap between the current data and original data, as both original and current data remain in the same continuous piece of memory
            MCore::MemMove(m_data + (m_numAttributes - numAttribsToRemove) * m_attribSizeInBytes, orgData, (m_numAttributes - numAttribsToRemove) * m_attribSizeInBytes);
        }

        // decrease the number of attributes
        m_numAttributes -= numAttribsToRemove;

        // reallocate, to make the data array smaller
        const uint32 numBytes = CalcTotalDataSizeInBytes(m_keepOriginals);
        m_data = (uint8*)MCore::AlignedRealloc(m_data, numBytes, numOriginalBytes, 16, EMFX_MEMCATEGORY_GEOMETRY_VERTEXATTRIBUTES);
    }