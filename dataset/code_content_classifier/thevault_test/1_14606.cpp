ActivityEdgeImpl::ActivityEdgeImpl(std::weak_ptr<uml::Activity > par_activity)
:ActivityEdgeImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}