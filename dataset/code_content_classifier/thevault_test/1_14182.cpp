InvocationActionImpl::InvocationActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:InvocationActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}