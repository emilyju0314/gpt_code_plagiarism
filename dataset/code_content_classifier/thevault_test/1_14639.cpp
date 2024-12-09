RegionImpl::RegionImpl(std::weak_ptr<uml::StateMachine > par_stateMachine)
:RegionImpl()
{
	m_stateMachine = par_stateMachine;
	m_namespace = par_stateMachine;
}