ExpansionRegionImpl::ExpansionRegionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ExpansionRegionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}