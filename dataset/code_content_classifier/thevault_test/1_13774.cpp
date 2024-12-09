std::shared_ptr<Bag<uml::PackageableElement>> DeploymentTargetImpl::getDeployedElement() const
{
	if(m_deployedElement == nullptr)
	{
		m_deployedElement.reset(new Bag<uml::PackageableElement>());
		
		
	}

    return m_deployedElement;
}