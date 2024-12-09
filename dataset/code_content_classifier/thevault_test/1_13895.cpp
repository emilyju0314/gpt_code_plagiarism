PackageImpl::PackageImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:PackageImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}