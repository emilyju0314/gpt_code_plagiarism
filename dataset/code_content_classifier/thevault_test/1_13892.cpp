PackageImpl::PackageImpl(std::weak_ptr<uml::Namespace > par_namespace)
:PackageImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}