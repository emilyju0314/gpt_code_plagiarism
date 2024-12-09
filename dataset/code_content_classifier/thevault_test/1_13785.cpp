PackageableElementImpl::PackageableElementImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:PackageableElementImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}