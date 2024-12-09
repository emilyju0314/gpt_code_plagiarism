DataStoreNodeImpl::DataStoreNodeImpl(std::weak_ptr<uml::Activity > par_activity)
:DataStoreNodeImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}