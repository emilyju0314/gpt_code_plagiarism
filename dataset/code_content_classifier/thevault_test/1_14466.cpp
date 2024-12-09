PortImpl::PortImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:PortImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}