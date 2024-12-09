PropertyImpl::PropertyImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:PropertyImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}