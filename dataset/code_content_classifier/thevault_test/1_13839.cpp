JoinNodeImpl::JoinNodeImpl(std::weak_ptr<uml::Namespace > par_namespace)
:JoinNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}