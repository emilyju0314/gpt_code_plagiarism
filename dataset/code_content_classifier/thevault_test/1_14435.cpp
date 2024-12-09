OpaqueBehaviorImpl::OpaqueBehaviorImpl(std::weak_ptr<uml::Namespace > par_namespace)
:OpaqueBehaviorImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}