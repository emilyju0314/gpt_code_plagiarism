std::shared_ptr<Bag<uml::Transition>> VertexImpl::getOutgoing() const
{
	if(m_outgoing == nullptr)
	{
		m_outgoing.reset(new Bag<uml::Transition>());
		
		
	}

    return m_outgoing;
}