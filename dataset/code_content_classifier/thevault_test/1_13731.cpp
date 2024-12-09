std::shared_ptr<Bag<ecore::EGenericType>> EOperationImpl::getEGenericExceptions() const
{
	if(m_eGenericExceptions == nullptr)
	{
		m_eGenericExceptions.reset(new Bag<ecore::EGenericType>());
		
		
	}

    return m_eGenericExceptions;
}