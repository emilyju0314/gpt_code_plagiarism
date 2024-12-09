bool WisdomContainer::getEntry(const std::string &path,
                               const std::string &name,
                               IWisdomContainerEntry::EntryType type,
                               IWisdomContainerEntry *&entry)
{
    if ( !isOpen() )
    {
        return false;
    }

    entry = 0;

    const string fname(entryFilename(path, name));
    // gLogDebug << "getEntry for root=[" << m_root << "] path=[" << path <<
    //        "] name=[" << name << "] type=" << int(type) << " fname=[" << fname << "]" << endl;


    bool ok;
    NvDlaFileHandle file;
    NvDlaError rc = NvDlaFopen((m_root + fname).c_str(), NVDLA_OPEN_READ, &file);
    ok = rc == NvDlaSuccess;
    if (!ok)
    {
        // gLogError << "couldn't open (read) entry file " << fname << endl;
    }
    else
    {
        NvDlaFclose(file);
        if ( type == IWisdomContainerEntry::ENTRY_TYPE_OBJECT ) {
            // gLogError << "open ok, instance new (dir) entry... " << fname << endl;
            std::string dirname = path;
            if ( name.size() && (name != string(".")) ) {
                dirname += "/" + name;
            }
            entry = new WisdomContainerEntry(this, dirname, string(""), type);

        } else {
            // gLogError << "open ok, instance new entry... " << fname << endl;
            entry = new WisdomContainerEntry(this, path, name, type);
        }
    }

    return ok && entry;
}