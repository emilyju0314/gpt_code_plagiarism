CallEventImpl::CallEventImpl(std::weak_ptr<uml::Namespace > par_namespace)
:CallEventImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}