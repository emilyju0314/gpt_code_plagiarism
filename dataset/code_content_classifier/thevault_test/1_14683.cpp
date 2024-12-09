CallActionImpl::CallActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:CallActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}