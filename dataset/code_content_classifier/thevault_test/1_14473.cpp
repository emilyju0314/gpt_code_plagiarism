LinkActionImpl::LinkActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:LinkActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}