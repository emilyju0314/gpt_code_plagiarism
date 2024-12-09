std::shared_ptr<Bag<uml::Generalization>> GeneralizationSetImpl::getGeneralization() const
{
	if(m_generalization == nullptr)
	{
		m_generalization.reset(new Bag<uml::Generalization>());
		
		
	}

    return m_generalization;
}