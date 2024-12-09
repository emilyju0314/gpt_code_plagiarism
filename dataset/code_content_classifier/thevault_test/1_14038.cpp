AddVariableValueActionImpl::AddVariableValueActionImpl(std::weak_ptr<uml::Activity > par_activity)
:AddVariableValueActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}