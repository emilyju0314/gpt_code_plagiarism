WriteLinkActionImpl::WriteLinkActionImpl(std::weak_ptr<uml::Activity > par_activity)
:WriteLinkActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}