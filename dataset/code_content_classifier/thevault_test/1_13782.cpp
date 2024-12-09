PackageableElementImpl::PackageableElementImpl(std::weak_ptr<uml::Namespace > par_namespace)
:PackageableElementImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}