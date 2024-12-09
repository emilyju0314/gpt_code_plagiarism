InstanceValueImpl::InstanceValueImpl(std::weak_ptr<uml::Namespace > par_namespace)
:InstanceValueImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}