TimeEventImpl::TimeEventImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:TimeEventImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}