PortImpl::PortImpl(std::weak_ptr<uml::Namespace > par_namespace)
:PortImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}