ChunkProcessor* Importer::FindChunk(uint32 chunkID, uint32 version) const
    {
        // for all chunk processors
        const auto foundProcessor = AZStd::find_if(begin(m_chunkProcessors), end(m_chunkProcessors), [chunkID, version](const ChunkProcessor* processor)
        {
            return processor->GetChunkID() == chunkID && processor->GetVersion() == version;
        });
        return foundProcessor != end(m_chunkProcessors) ? *foundProcessor : nullptr;
    }