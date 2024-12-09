void
    SoundBufferIO::initialize()
    {
        if (m_bufferByteSize % sizeof(int16_t) != 0)
            throw std::exception(String("Sound error: Sound buffer size must be a multiple of '%'").arg(sizeof(int16_t)).c_str());

        std::ifstream fileStream(m_filePath, std::ios::in | std::ios::binary);
        if (!fileStream)
            throw std::exception(String("IO error: Unable to open file '%'").arg(m_filePath).c_str());

        bool reachedDataChunk = false;

        while (fileStream &&
               !reachedDataChunk)
        {
            auto const chunkId = readNextElement<int32_t>(fileStream);
            auto const chunkSize = readNextElement<int32_t>(fileStream);

            switch (static_cast<EChunkType>(chunkId))
            {
            case EChunkType::RiffHeader:
                m_riffHeaderChunkId = chunkId;
                m_riffHeaderChunkSize = chunkSize;
                m_format = readNextElement<int32_t>(fileStream);
                break;
            case EChunkType::Format:
                m_formatChunkId = chunkId;
                m_formatChunkSize = chunkSize;
                m_audioFormat = readNextElement<int16_t>(fileStream);
                m_channelCount = readNextElement<int16_t>(fileStream);
                m_sampleRate = readNextElement<int32_t>(fileStream);
                m_byteRate = readNextElement<int32_t>(fileStream);
                m_bytesPerBlock = readNextElement<int16_t>(fileStream);
                m_bitDepth = readNextElement<int16_t>(fileStream);

                if (chunkSize == 18)
                    fileStream.ignore(readNextElement<int16_t>(fileStream));

                break;
            case EChunkType::Data:
            {
                m_dataChunkId = chunkId;
                m_dataChunkSize = static_cast<size_t>(chunkSize);
                m_dataChunkPosition = fileStream.tellg();
                reachedDataChunk = true;
                break;
            }
            default:
                fileStream.ignore(chunkSize);
                break;
            }
        }

        if (!reachedDataChunk)
            throw std::exception(String("IO error: File '%' may be corrupted").arg(m_filePath).c_str());

        if (m_bitDepth != 16 ||
            m_channelCount != 2)
            throw std::exception("Sound error: Sound format not supported");

        fileStream.close();
    }