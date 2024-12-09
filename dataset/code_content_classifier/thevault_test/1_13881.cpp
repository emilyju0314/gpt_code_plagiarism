TypeImpl::TypeImpl(std::weak_ptr<uml::Namespace > par_namespace)
:TypeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}