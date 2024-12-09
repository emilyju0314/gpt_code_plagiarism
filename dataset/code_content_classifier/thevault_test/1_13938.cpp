ReclassifyObjectActionImpl::ReclassifyObjectActionImpl(std::weak_ptr<uml::Activity > par_activity)
:ReclassifyObjectActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}