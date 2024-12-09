std::shared_ptr<Bag<uml::Type>> BehavioralFeatureImpl::getRaisedException() const
{
	if(m_raisedException == nullptr)
	{
		m_raisedException.reset(new Bag<uml::Type>());
		
		
	}

    return m_raisedException;
}