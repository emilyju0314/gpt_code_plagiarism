SizeType GenericStream::WriteAtOffset(SizeType bytes, const void* iBuffer, OffsetType offset)
    {
        if (offset >= 0)
        {
            Seek(offset, SeekMode::ST_SEEK_BEGIN);
        }
        return Write(bytes, iBuffer);
    }