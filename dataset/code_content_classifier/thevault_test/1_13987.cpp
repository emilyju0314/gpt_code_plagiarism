ActivityGroupImpl::ActivityGroupImpl(std::weak_ptr<uml::ActivityGroup > par_superGroup)
:ActivityGroupImpl()
{
	m_superGroup = par_superGroup;
	m_owner = par_superGroup;
}