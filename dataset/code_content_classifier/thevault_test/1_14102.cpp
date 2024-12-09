ForkNodeImpl::ForkNodeImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ForkNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}