ActorImpl::ActorImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ActorImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}