ProtocolStateMachineImpl::ProtocolStateMachineImpl(std::weak_ptr<uml::BehavioredClassifier > par_behavioredClassifier)
:ProtocolStateMachineImpl()
{
	m_behavioredClassifier = par_behavioredClassifier;
	m_namespace = par_behavioredClassifier;
}