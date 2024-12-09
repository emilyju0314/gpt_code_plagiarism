std::shared_ptr<Bag<uml::Behavior>> BehavioralFeatureImpl::getMethod() const
{
	if(m_method == nullptr)
	{
		m_method.reset(new Bag<uml::Behavior>());
		
		
	}

    return m_method;
}