EnumerationImpl::EnumerationImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:EnumerationImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}