ParameterImpl::ParameterImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:ParameterImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}