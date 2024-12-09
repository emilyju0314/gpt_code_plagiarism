std::shared_ptr<Bag<ecore::EReference>> EClassImpl::getEAllContainments() const
{
	if(m_eAllContainments == nullptr)
	{
		m_eAllContainments.reset(new Bag<ecore::EReference>());
		
		
	}

    return m_eAllContainments;
}