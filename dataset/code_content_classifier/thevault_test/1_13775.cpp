std::shared_ptr<Subset<uml::Deployment, uml::Element>> DeploymentTargetImpl::getDeployment() const
{
	if(m_deployment == nullptr)
	{
		/*Subset*/
		m_deployment.reset(new Subset<uml::Deployment, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_deployment - Subset<uml::Deployment, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_deployment->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_deployment - Subset<uml::Deployment, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_deployment;
}