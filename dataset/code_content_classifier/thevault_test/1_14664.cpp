InterfaceRealizationImpl::InterfaceRealizationImpl(std::weak_ptr<uml::BehavioredClassifier > par_implementingClassifier)
:InterfaceRealizationImpl()
{
	m_implementingClassifier = par_implementingClassifier;
	m_owner = par_implementingClassifier;
}