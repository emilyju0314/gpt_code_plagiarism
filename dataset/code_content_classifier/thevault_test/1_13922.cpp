std::shared_ptr<Bag<uml::Pseudostate>> ConnectionPointReferenceImpl::getEntry() const
{
	if(m_entry == nullptr)
	{
		m_entry.reset(new Bag<uml::Pseudostate>());
		
		
	}

    return m_entry;
}