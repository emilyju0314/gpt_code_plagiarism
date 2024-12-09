UsageImpl::UsageImpl(std::weak_ptr<uml::Namespace > par_namespace)
:UsageImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}