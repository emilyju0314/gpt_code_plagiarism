std::shared_ptr<Bag<ecore::EGenericType>> EGenericTypeImpl::getETypeArguments() const
{
	if(m_eTypeArguments == nullptr)
	{
		m_eTypeArguments.reset(new Bag<ecore::EGenericType>());
		
		
	}

    return m_eTypeArguments;
}