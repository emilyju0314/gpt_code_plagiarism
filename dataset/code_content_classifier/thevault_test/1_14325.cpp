ComponentImpl::ComponentImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ComponentImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}