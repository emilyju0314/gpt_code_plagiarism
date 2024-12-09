ConnectionPointReferenceImpl::ConnectionPointReferenceImpl(std::weak_ptr<uml::Region > par_container)
:ConnectionPointReferenceImpl()
{
	m_container = par_container;
	m_namespace = par_container;
}