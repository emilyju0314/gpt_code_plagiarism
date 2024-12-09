std::shared_ptr<Bag<uml::Interface>> ComponentImpl::getProvided() const
{
	if(m_provided == nullptr)
	{
		m_provided.reset(new Bag<uml::Interface>());
		
		
	}

    return m_provided;
}