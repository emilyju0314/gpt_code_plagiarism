ReadLinkActionImpl::ReadLinkActionImpl(std::weak_ptr<uml::Activity > par_activity)
:ReadLinkActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}