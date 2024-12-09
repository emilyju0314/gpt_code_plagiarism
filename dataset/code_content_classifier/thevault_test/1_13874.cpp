ObjectNodeImpl::ObjectNodeImpl(std::weak_ptr<uml::Activity > par_activity)
:ObjectNodeImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}