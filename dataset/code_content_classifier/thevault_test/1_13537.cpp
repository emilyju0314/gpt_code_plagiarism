void FileInfo::fillOutMessage(const IMessagePtr& out) const
{
    Locker lock(&m_lock);
    mod::Info::fillOutMessage(out);
    out->setData(msg::key::FILEPATH, m_path);
}