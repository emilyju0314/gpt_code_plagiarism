ComponentRealizationImpl::ComponentRealizationImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:ComponentRealizationImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}