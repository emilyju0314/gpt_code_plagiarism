RegionImpl::RegionImpl(std::weak_ptr<uml::State > par_state)
:RegionImpl()
{
	m_state = par_state;
	m_namespace = par_state;
}