SignalImpl::SignalImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:SignalImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}