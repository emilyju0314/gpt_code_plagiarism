DependencyImpl::DependencyImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:DependencyImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}