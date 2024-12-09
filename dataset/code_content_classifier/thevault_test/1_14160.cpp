ReadLinkActionImpl::ReadLinkActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ReadLinkActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}