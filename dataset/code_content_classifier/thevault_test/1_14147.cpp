ProtocolConformanceImpl::ProtocolConformanceImpl(std::weak_ptr<uml::ProtocolStateMachine > par_specificMachine)
:ProtocolConformanceImpl()
{
	m_specificMachine = par_specificMachine;
	m_owner = par_specificMachine;
}