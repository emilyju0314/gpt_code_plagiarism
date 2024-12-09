void DVInfo::fillOutMessage(const IMessagePtr& out) const
{
    Locker lock(&m_lock);
    mod::Info::fillOutMessage(out);
    out->setData(msg::key::IEEE1394PORT, m_port);
}