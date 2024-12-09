StructuralFeatureActionImpl::StructuralFeatureActionImpl(std::weak_ptr<uml::Activity > par_activity)
:StructuralFeatureActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}