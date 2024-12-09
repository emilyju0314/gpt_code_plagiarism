ReduceActionImpl::ReduceActionImpl(std::weak_ptr<uml::Activity > par_activity)
:ReduceActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}