CreateObjectActionImpl::CreateObjectActionImpl(std::weak_ptr<uml::Activity > par_activity)
:CreateObjectActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}