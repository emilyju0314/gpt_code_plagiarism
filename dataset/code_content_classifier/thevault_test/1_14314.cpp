DurationIntervalImpl::DurationIntervalImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:DurationIntervalImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}