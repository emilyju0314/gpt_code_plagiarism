BehaviorImpl::BehaviorImpl(std::weak_ptr<uml::BehavioredClassifier > par_behavioredClassifier)
:BehaviorImpl()
{
	m_behavioredClassifier = par_behavioredClassifier;
	m_namespace = par_behavioredClassifier;
}