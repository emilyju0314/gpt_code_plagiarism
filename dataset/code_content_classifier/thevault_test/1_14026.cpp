std::shared_ptr<Bag<uml::Port>> TriggerImpl::getPort() const
{
	if(m_port == nullptr)
	{
		m_port.reset(new Bag<uml::Port>());
		
		
	}

    return m_port;
}