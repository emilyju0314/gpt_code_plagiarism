std::shared_ptr<Bag<uml::ActivityEdge>> ActivityNodeImpl::getIncoming() const
{
	if(m_incoming == nullptr)
	{
		m_incoming.reset(new Bag<uml::ActivityEdge>());
		
		
	}

    return m_incoming;
}