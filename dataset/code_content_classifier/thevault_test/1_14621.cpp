FinalStateImpl::FinalStateImpl(std::weak_ptr<uml::Namespace > par_namespace)
:FinalStateImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}