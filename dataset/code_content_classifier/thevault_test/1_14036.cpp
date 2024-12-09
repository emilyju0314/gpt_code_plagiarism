ManifestationImpl::ManifestationImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:ManifestationImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}