DeploymentImpl::DeploymentImpl(std::weak_ptr<uml::DeploymentTarget > par_location)
:DeploymentImpl()
{
	m_location = par_location;
	m_owner = par_location;
}