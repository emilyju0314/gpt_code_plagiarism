ProtocolTransitionImpl::ProtocolTransitionImpl(std::weak_ptr<uml::Region > par_container)
:ProtocolTransitionImpl()
{
	m_container = par_container;
	m_namespace = par_container;
}