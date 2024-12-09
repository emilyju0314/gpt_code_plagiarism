std::shared_ptr<Bag<uml::Package>> CS_ExecutionFactoryImpl::getAppliedProfiles() const
{
	if(m_appliedProfiles == nullptr)
	{
		m_appliedProfiles.reset(new Bag<uml::Package>());
		
		
	}

    return m_appliedProfiles;
}