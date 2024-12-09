DependencyImpl::DependencyImpl(std::weak_ptr<uml::Namespace > par_namespace)
:DependencyImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}