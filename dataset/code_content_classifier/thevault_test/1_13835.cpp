SignalEventImpl::SignalEventImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:SignalEventImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}