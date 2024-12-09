WisdomContainer::WisdomContainer(Wisdom *wisdom) :
    IWisdomContainer(wisdom),
    m_wisdom(wisdom),
    m_wisdom_priv(wisdom),
    m_root(""),
    m_root_entry(this, string(""), string(""), IWisdomContainerEntry::ENTRY_TYPE_OBJECT)
{

}