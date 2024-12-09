IntervalImpl::IntervalImpl(std::weak_ptr<uml::Namespace > par_namespace)
:IntervalImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}