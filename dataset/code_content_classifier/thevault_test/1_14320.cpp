PseudostateImpl::PseudostateImpl(std::weak_ptr<uml::StateMachine > par_stateMachine)
:PseudostateImpl()
{
	m_stateMachine = par_stateMachine;
	m_namespace = par_stateMachine;
}