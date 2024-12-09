GeneralizationSetImpl::GeneralizationSetImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:GeneralizationSetImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}