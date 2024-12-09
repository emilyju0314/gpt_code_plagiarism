std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> ExecutionImpl::getParameterValues() const
{
	if(m_parameterValues == nullptr)
	{
		m_parameterValues.reset(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());
		
		
	}

    return m_parameterValues;
}