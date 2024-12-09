std::shared_ptr<Bag<uml::Relationship>> InformationFlowImpl::getRealization() const
{
	if(m_realization == nullptr)
	{
		m_realization.reset(new Bag<uml::Relationship>());
		
		
	}

    return m_realization;
}