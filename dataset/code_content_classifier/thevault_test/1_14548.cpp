std::shared_ptr<Bag<ecore::EClass>> EClassImpl::getESuperTypes() const
{
	if(m_eSuperTypes == nullptr)
	{
		m_eSuperTypes.reset(new Bag<ecore::EClass>());
		
		
	}

    return m_eSuperTypes;
}