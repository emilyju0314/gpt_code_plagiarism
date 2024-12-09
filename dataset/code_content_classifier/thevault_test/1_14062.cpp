std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>> LocusImpl::getExtensionalValues() const
{
	if(m_extensionalValues == nullptr)
	{
		m_extensionalValues.reset(new Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>());
		
		
	}

    return m_extensionalValues;
}