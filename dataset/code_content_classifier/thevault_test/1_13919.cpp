ConnectionPointReferenceImpl::ConnectionPointReferenceImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ConnectionPointReferenceImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}