TypeImpl::TypeImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:TypeImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}