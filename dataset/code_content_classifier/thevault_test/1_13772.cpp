DeploymentTargetImpl::DeploymentTargetImpl(std::weak_ptr<uml::Namespace > par_namespace)
:DeploymentTargetImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}