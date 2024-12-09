std::shared_ptr<Bag<ecore::EClassifier>> EOperationImpl::getEExceptions() const
{
	if(m_eExceptions == nullptr)
	{
		m_eExceptions.reset(new Bag<ecore::EClassifier>());
		
		
	}

    return m_eExceptions;
}