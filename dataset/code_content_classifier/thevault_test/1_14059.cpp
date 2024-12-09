ExtensionImpl::ExtensionImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:ExtensionImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}