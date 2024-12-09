RemoveVariableValueActionImpl::RemoveVariableValueActionImpl(std::weak_ptr<uml::Activity > par_activity)
:RemoveVariableValueActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}