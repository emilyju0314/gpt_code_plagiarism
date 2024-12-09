DeploymentImpl::DeploymentImpl(std::weak_ptr<uml::Package > par_owningPackage)
:DeploymentImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}