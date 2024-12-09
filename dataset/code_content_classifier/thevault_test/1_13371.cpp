const IReaderPtr Factory::getReader(const std::string& media_type,
                                    const ISocketPtr& sock) const
{
    BOOST_ASSERT(media_type.empty() == false);
    BOOST_ASSERT(sock);

    MakeReaderStorage::const_iterator find = m_readers.find(media_type);

    if (find == m_readers.end())
    {
        throw Exception(__FILE__, __LINE__,
                        "Unsupported media type for HTTP streamer: " +
                        media_type);
    }

    return (find->second)(sock);
}