std::shared_ptr<Bag<uml::ParameterSet>> ParameterImpl::getParameterSet() const
{
	if(m_parameterSet == nullptr)
	{
		m_parameterSet.reset(new Bag<uml::ParameterSet>());
		
		
	}

    return m_parameterSet;
}