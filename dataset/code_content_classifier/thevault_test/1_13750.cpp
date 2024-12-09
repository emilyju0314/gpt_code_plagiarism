UsageImpl::UsageImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:UsageImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}