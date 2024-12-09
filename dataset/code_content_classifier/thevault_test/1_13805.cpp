StructuralFeatureActionImpl::StructuralFeatureActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:StructuralFeatureActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}