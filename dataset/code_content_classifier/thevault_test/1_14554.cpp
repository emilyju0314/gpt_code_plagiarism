DestroyObjectActionImpl::DestroyObjectActionImpl(std::weak_ptr<uml::Activity > par_activity)
:DestroyObjectActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}