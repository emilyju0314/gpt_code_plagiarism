DeploymentImpl::DeploymentImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:DeploymentImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}