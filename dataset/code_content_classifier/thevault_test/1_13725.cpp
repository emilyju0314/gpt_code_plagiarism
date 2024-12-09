std::shared_ptr<Bag<uml::GeneralOrdering>> OccurrenceSpecificationImpl::getToBefore() const
{
	if(m_toBefore == nullptr)
	{
		m_toBefore.reset(new Bag<uml::GeneralOrdering>());
		
		
	}

    return m_toBefore;
}