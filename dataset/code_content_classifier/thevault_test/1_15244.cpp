bool WisdomContainer::readUInt8Vector(const std::string &path, NvU8 **ret_vals, size_t *ret_size)
{
    NvDlaFileHandle file;
    NvDlaStatType finfo;
    size_t file_size;

    if ( !ret_size ) {
        return false;
    }

    NvDlaError rc = NvDlaFopen((m_root + entryFilename(path)).c_str(), NVDLA_OPEN_READ, &file);
    if (rc != NvDlaSuccess)
    {
        gLogError << "couldn't open entry " << entryFilename(path) << endl;
        return false;
    }

    rc = NvDlaFstat(file, &finfo);
    if ( rc != NvDlaSuccess)
    {
        gLogError << "couldn't get file stats for " << entryFilename(path) << endl;
        return false;
    }
    file_size = finfo.size;

    *ret_size = file_size;

    if ( NULL == ret_vals ) {
        return true;
    }
    if ( !file_size )  {
        return true;
    }
    if ( NULL == (*ret_vals) ) {
        *ret_vals = new NvU8[file_size];
        if ( NULL == (*ret_vals) ) {
            gLogError << " oom" << entryFilename(path) << endl;
            return false;
        }
    }
    NvDlaFseek(file, 0, NvDlaSeek_Set);

    size_t actually_read = 0;
    NVDLA_UNUSED(actually_read);

    rc = NvDlaFread(file, *ret_vals, file_size, ret_size);
    if ( rc != NvDlaSuccess )
    {
        return false;
    }
    if ( *ret_size != file_size )
    {
        return false;
    }

    NvDlaFclose(file);

    return true;
}