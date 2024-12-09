CallEventImpl::CallEventImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:CallEventImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}