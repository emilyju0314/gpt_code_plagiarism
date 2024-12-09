ExpansionRegionImpl::ExpansionRegionImpl(std::weak_ptr<uml::ActivityGroup > par_superGroup)
:ExpansionRegionImpl()
{
	m_superGroup = par_superGroup;
	m_owner = par_superGroup;
}