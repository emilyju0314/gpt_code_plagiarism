DataStoreNodeImpl::DataStoreNodeImpl(std::weak_ptr<uml::Namespace > par_namespace)
:DataStoreNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}