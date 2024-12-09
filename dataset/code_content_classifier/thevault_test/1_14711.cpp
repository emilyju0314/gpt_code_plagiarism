PropertyImpl::PropertyImpl(std::weak_ptr<uml::Namespace > par_namespace)
:PropertyImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}