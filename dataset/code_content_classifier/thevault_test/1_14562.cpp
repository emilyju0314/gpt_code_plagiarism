std::shared_ptr<Bag<uml::Class>> CS_DefaultConstructStrategyImpl::getGeneratedRealizingClasses() const
{
	if(m_generatedRealizingClasses == nullptr)
	{
		m_generatedRealizingClasses.reset(new Bag<uml::Class>());
		
		
	}

    return m_generatedRealizingClasses;
}