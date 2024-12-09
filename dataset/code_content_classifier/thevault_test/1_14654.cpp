std::shared_ptr<Bag<uml::ActivityEdge>> ActivityNodeImpl::getOutgoing() const
{
	if(m_outgoing == nullptr)
	{
		m_outgoing.reset(new Bag<uml::ActivityEdge>());
		
		
	}

    return m_outgoing;
}