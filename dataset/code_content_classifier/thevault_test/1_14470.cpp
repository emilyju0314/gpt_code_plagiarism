std::shared_ptr<Bag<uml::Interface>> PortImpl::getRequired() const
{
	if(m_required == nullptr)
	{
		m_required.reset(new Bag<uml::Interface>());
		
		
	}

    return m_required;
}