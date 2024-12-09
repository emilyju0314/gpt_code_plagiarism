ExtensionPointImpl::ExtensionPointImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ExtensionPointImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}