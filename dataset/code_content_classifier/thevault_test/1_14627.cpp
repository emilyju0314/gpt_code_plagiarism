ParameterableElementImpl::ParameterableElementImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:ParameterableElementImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}