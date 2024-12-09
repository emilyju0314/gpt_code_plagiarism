ChangeEventImpl::ChangeEventImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:ChangeEventImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}