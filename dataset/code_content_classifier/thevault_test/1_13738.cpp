std::shared_ptr<Bag<uml::InteractionFragment>> LifelineImpl::getCoveredBy() const
{
	if(m_coveredBy == nullptr)
	{
		m_coveredBy.reset(new Bag<uml::InteractionFragment>());
		
		
	}

    return m_coveredBy;
}