EventImpl::EventImpl(std::weak_ptr<uml::Namespace > par_namespace)
:EventImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}