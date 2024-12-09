TimeEventImpl::TimeEventImpl(std::weak_ptr<uml::Namespace > par_namespace)
:TimeEventImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}