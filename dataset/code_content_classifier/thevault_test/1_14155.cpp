std::shared_ptr<Subset<uml::DeploymentSpecification, uml::Element>> DeploymentImpl::getConfiguration() const
{
	if(m_configuration == nullptr)
	{
		/*Subset*/
		m_configuration.reset(new Subset<uml::DeploymentSpecification, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_configuration - Subset<uml::DeploymentSpecification, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_configuration->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_configuration - Subset<uml::DeploymentSpecification, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_configuration;
}