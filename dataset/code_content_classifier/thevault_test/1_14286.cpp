std::shared_ptr<Bag<uml::Operation>> ProtocolTransitionImpl::getReferred() const
{
	if(m_referred == nullptr)
	{
		m_referred.reset(new Bag<uml::Operation>());
		
		
	}

    return m_referred;
}