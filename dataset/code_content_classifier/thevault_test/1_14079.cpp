std::shared_ptr<Bag<uml::GeneralizationSet>> GeneralizationImpl::getGeneralizationSet() const
{
	if(m_generalizationSet == nullptr)
	{
		m_generalizationSet.reset(new Bag<uml::GeneralizationSet>());
		
		
	}

    return m_generalizationSet;
}