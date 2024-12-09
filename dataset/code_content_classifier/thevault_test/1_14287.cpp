SignalImpl::SignalImpl(std::weak_ptr<uml::Namespace > par_namespace)
:SignalImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}