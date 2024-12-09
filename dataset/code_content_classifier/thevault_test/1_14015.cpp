StateInvariantImpl::StateInvariantImpl(std::weak_ptr<uml::Namespace > par_namespace)
:StateInvariantImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}