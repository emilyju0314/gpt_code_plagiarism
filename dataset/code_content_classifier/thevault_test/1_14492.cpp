DecisionNodeImpl::DecisionNodeImpl(std::weak_ptr<uml::Activity > par_activity)
:DecisionNodeImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}