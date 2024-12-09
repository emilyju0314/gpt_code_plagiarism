ChangeEventImpl::ChangeEventImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ChangeEventImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}