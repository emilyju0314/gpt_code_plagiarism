AddStructuralFeatureValueActionImpl::AddStructuralFeatureValueActionImpl(std::weak_ptr<uml::Activity > par_activity)
:AddStructuralFeatureValueActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}