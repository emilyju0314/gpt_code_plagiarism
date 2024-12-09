ForkNodeImpl::ForkNodeImpl(std::weak_ptr<uml::Activity > par_activity)
:ForkNodeImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}