NamespaceImpl::NamespaceImpl(std::weak_ptr<uml::Namespace > par_namespace)
:NamespaceImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}