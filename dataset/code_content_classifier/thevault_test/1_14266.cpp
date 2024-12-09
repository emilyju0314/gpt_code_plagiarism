AcceptCallActionImpl::AcceptCallActionImpl(std::weak_ptr<uml::Activity > par_activity)
:AcceptCallActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}