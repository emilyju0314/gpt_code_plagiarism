SizeType GenericStream::ReadAtOffset(SizeType bytes, void* oBuffer, OffsetType offset)
    {
        if (offset >= 0)
        {
            Seek(offset, SeekMode::ST_SEEK_BEGIN);
        }
        return Read(bytes, oBuffer);
    }