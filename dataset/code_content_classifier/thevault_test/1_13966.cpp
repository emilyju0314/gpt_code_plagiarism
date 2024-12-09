IntervalImpl::IntervalImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:IntervalImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}