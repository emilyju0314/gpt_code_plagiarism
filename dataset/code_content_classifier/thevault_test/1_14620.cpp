FinalStateImpl::FinalStateImpl(std::weak_ptr<uml::Region > par_container)
:FinalStateImpl()
{
	m_container = par_container;
	m_namespace = par_container;
}