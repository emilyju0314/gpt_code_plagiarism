InformationItemImpl::InformationItemImpl(std::weak_ptr<uml::Namespace > par_namespace)
:InformationItemImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}