ActionImpl::ActionImpl(std::weak_ptr<uml::Activity > par_activity)
:ActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}