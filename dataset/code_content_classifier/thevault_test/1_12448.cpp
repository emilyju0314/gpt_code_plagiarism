size_t DiskFile::GetPos() const
    {
        MCORE_ASSERT(m_file);

        return ftello(m_file);
    }