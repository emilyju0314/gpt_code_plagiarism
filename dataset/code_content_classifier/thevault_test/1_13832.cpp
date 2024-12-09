SignalEventImpl::SignalEventImpl(std::weak_ptr<uml::Namespace > par_namespace)
:SignalEventImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}