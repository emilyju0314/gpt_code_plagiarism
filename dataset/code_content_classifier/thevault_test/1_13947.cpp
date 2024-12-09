BehavioralFeatureImpl::BehavioralFeatureImpl(std::weak_ptr<uml::Namespace > par_namespace)
:BehavioralFeatureImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}