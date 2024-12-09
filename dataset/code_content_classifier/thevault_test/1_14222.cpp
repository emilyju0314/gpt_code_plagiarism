std::shared_ptr<Bag<ecore::EObject>> EAnnotationImpl::getReferences() const
{
	if(m_references == nullptr)
	{
		m_references.reset(new Bag<ecore::EObject>());
		
		
	}

    return m_references;
}