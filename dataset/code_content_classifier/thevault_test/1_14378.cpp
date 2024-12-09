OpaqueActionImpl::OpaqueActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:OpaqueActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}