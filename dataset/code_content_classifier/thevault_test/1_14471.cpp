LinkActionImpl::LinkActionImpl(std::weak_ptr<uml::Activity > par_activity)
:LinkActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}