std::shared_ptr<Bag<ecore::EGenericType>> ETypeParameterImpl::getEBounds() const
{
	if(m_eBounds == nullptr)
	{
		m_eBounds.reset(new Bag<ecore::EGenericType>());
		
		
	}

    return m_eBounds;
}