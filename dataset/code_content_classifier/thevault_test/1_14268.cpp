AcceptCallActionImpl::AcceptCallActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:AcceptCallActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}