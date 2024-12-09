ControlFlowImpl::ControlFlowImpl(std::weak_ptr<uml::Activity > par_activity)
:ControlFlowImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}