CallBehaviorActionImpl::CallBehaviorActionImpl(std::weak_ptr<uml::Activity > par_activity)
:CallBehaviorActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}