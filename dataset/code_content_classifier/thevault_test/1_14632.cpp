AcceptEventActionImpl::AcceptEventActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:AcceptEventActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}