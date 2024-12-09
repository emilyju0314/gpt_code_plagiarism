void FileInfo::check(const IMessagePtr& in) const
{
    BOOST_ASSERT(in);
    const std::string mode = in->getValue(msg::key::FILEMODE);
    if (mode == msg::key::FILEREAD)
    {
        if (exist() == false)
        {
            m_factory->getSNMP()->sendTrap(TRAP_FILEMISSING,
                                         getPath());
            throw Exception(__FILE__, __LINE__,
                            "File '%s' at path '%s' does not exist",
                            getName().c_str(),
                            getPath().c_str());
        }
    }
    else if (mode == msg::key::FILEWRITE)
    {
        // request should be start
        if (in->getID() != msg::id::FILESTART)
        {
            throw Exception(__FILE__, __LINE__,
                            "Write operation should be locked. "
                            "Name: %s. Path: %s",
                            getName().c_str(),
                            getPath().c_str());

        }
    }
    else
    {
        throw Exception(__FILE__, __LINE__,
                        "Unknown file mode '%s'", mode.c_str());
    }
}