OpaqueBehaviorImpl::OpaqueBehaviorImpl(std::weak_ptr<uml::BehavioredClassifier > par_behavioredClassifier)
:OpaqueBehaviorImpl()
{
	m_behavioredClassifier = par_behavioredClassifier;
	m_namespace = par_behavioredClassifier;
}