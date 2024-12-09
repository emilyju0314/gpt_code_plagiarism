StereotypeImpl::StereotypeImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:StereotypeImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}