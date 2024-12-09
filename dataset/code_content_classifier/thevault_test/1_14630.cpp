AcceptEventActionImpl::AcceptEventActionImpl(std::weak_ptr<uml::Activity > par_activity)
:AcceptEventActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}