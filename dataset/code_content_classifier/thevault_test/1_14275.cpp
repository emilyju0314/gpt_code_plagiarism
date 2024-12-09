AssociationClassImpl::AssociationClassImpl(std::weak_ptr<uml::Namespace > par_namespace)
:AssociationClassImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}