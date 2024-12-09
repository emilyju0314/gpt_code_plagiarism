std::shared_ptr<Bag<uml::Transition>> VertexImpl::getIncoming() const
{
	if(m_incoming == nullptr)
	{
		m_incoming.reset(new Bag<uml::Transition>());
		
		
	}

    return m_incoming;
}