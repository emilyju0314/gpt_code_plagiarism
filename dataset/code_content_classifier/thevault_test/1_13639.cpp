InitialNodeImpl::InitialNodeImpl(std::weak_ptr<uml::Namespace > par_namespace)
:InitialNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}