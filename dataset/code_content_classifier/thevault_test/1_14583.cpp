ClearAssociationActionImpl::ClearAssociationActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ClearAssociationActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}