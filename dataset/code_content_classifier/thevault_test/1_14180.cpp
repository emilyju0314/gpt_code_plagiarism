InvocationActionImpl::InvocationActionImpl(std::weak_ptr<uml::Activity > par_activity)
:InvocationActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}