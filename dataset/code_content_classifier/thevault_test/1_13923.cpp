std::shared_ptr<Bag<uml::Pseudostate>> ConnectionPointReferenceImpl::getExit() const
{
	if(m_exit == nullptr)
	{
		m_exit.reset(new Bag<uml::Pseudostate>());
		
		
	}

    return m_exit;
}