VariableActionImpl::VariableActionImpl(std::weak_ptr<uml::Activity > par_activity)
:VariableActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}