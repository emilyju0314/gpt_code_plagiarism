StructuralFeatureImpl::StructuralFeatureImpl(std::weak_ptr<uml::Namespace > par_namespace)
:StructuralFeatureImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}