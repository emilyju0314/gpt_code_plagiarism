EventImpl::EventImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:EventImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}