CallActionImpl::CallActionImpl(std::weak_ptr<uml::Activity > par_activity)
:CallActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}