RegionImpl::RegionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:RegionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}