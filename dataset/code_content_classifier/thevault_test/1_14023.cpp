TriggerImpl::TriggerImpl(std::weak_ptr<uml::Namespace > par_namespace)
:TriggerImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}