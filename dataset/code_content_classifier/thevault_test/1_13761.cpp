EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:EnumerationLiteralImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}