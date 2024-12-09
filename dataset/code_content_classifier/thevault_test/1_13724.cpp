std::shared_ptr<Bag<uml::GeneralOrdering>> OccurrenceSpecificationImpl::getToAfter() const
{
	if(m_toAfter == nullptr)
	{
		m_toAfter.reset(new Bag<uml::GeneralOrdering>());
		
		
	}

    return m_toAfter;
}