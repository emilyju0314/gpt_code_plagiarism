InteractionImpl::InteractionImpl(std::weak_ptr<uml::BehavioredClassifier > par_behavioredClassifier)
:InteractionImpl()
{
	m_behavioredClassifier = par_behavioredClassifier;
	m_namespace = par_behavioredClassifier;
}