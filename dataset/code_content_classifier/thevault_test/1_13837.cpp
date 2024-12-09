JoinNodeImpl::JoinNodeImpl(std::weak_ptr<uml::Activity > par_activity)
:JoinNodeImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}