std::shared_ptr<Bag<ecore::EGenericType>> EClassImpl::getEAllGenericSuperTypes() const
{
	if(m_eAllGenericSuperTypes == nullptr)
	{
		m_eAllGenericSuperTypes.reset(new Bag<ecore::EGenericType>());
		
		
	}

    return m_eAllGenericSuperTypes;
}