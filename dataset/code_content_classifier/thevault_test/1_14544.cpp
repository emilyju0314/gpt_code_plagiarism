std::shared_ptr<Bag<ecore::EGenericType>> EClassImpl::getEGenericSuperTypes() const
{
	if(m_eGenericSuperTypes == nullptr)
	{
		m_eGenericSuperTypes.reset(new Bag<ecore::EGenericType>());
		
		
	}

    return m_eGenericSuperTypes;
}