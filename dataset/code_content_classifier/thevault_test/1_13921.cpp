ConnectionPointReferenceImpl::ConnectionPointReferenceImpl(std::weak_ptr<uml::State > par_state)
:ConnectionPointReferenceImpl()
{
	m_state = par_state;
	m_namespace = par_state;
}