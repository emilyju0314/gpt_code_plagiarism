ActivityNodeImpl::ActivityNodeImpl(std::weak_ptr<uml::Activity > par_activity)
:ActivityNodeImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}