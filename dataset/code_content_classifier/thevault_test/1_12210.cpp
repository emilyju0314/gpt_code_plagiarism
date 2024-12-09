void VertexAttributeLayerAbstractData::RemoveSwapBuffer()
    {
        MCore::AlignedFree(m_swapBuffer);
        m_swapBuffer = nullptr;
    }