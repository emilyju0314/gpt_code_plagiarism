InterfaceImpl::InterfaceImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:InterfaceImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}