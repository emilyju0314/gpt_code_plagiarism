InterfaceImpl::InterfaceImpl(std::weak_ptr<uml::Namespace > par_namespace)
:InterfaceImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}