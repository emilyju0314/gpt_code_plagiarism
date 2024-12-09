void FolderInfo::check(const IMessagePtr& in) const
{
    BOOST_ASSERT(in);
    const std::string mode = in->getValue(msg::key::FILEMODE);
    if (mode == msg::key::FILEREAD)
    {
        // we could not ask it for folder (it's undefined)
        throw Exception(__FILE__, __LINE__,
                        "Read operation is undefined for folder. "
                        "Name: %s. Path: %s",
                        getName().c_str(),
                        getPath().c_str());
    }

    // base check
    FileInfo::check(in);
}