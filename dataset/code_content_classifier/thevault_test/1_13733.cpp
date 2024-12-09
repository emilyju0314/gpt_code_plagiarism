std::shared_ptr<Bag<ecore::ETypeParameter>> EOperationImpl::getETypeParameters() const
{
	if(m_eTypeParameters == nullptr)
	{
		m_eTypeParameters.reset(new Bag<ecore::ETypeParameter>());
		
		
	}

    return m_eTypeParameters;
}