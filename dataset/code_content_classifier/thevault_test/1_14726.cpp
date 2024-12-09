ExpansionNodeImpl::ExpansionNodeImpl(std::weak_ptr<uml::Activity > par_activity)
:ExpansionNodeImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}