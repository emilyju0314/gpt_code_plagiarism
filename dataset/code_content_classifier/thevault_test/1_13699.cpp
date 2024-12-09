IncludeImpl::IncludeImpl(std::weak_ptr<uml::Namespace > par_namespace)
:IncludeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}