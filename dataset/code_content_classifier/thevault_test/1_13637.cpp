InitialNodeImpl::InitialNodeImpl(std::weak_ptr<uml::Activity > par_activity)
:InitialNodeImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}