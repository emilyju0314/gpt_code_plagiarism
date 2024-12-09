FunctionBehaviorImpl::FunctionBehaviorImpl(std::weak_ptr<uml::BehavioredClassifier > par_behavioredClassifier)
:FunctionBehaviorImpl()
{
	m_behavioredClassifier = par_behavioredClassifier;
	m_namespace = par_behavioredClassifier;
}