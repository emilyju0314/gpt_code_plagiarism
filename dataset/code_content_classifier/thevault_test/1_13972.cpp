FeatureImpl::FeatureImpl(std::weak_ptr<uml::Namespace > par_namespace)
:FeatureImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}