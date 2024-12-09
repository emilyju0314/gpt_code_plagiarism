ComponentImpl::ComponentImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:ComponentImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}