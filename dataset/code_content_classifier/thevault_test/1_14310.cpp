DurationIntervalImpl::DurationIntervalImpl(std::weak_ptr<uml::Namespace > par_namespace)
:DurationIntervalImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}