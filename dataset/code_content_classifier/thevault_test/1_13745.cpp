WriteLinkActionImpl::WriteLinkActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:WriteLinkActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}