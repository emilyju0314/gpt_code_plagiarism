ActionImpl::ActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}