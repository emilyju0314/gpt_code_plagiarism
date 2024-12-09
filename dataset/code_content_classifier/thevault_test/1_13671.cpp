CommunicationPathImpl::CommunicationPathImpl(std::weak_ptr<uml::Namespace > par_namespace)
:CommunicationPathImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}