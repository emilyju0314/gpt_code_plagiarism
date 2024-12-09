AbstractionImpl::AbstractionImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:AbstractionImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}