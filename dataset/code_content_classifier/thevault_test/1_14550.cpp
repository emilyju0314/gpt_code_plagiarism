std::shared_ptr<Bag<fUML::Semantics::Values::Value>> ParameterValueImpl::getValues() const
{
	if(m_values == nullptr)
	{
		m_values.reset(new Bag<fUML::Semantics::Values::Value>());
		
		
	}

    return m_values;
}