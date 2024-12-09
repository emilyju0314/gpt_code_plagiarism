std::shared_ptr<Bag<uml::NamedElement>> ConsiderIgnoreFragmentImpl::getMessage() const
{
	if(m_message == nullptr)
	{
		m_message.reset(new Bag<uml::NamedElement>());
		
		
	}

    return m_message;
}