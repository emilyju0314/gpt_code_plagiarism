SlotImpl::SlotImpl(std::weak_ptr<uml::InstanceSpecification > par_owningInstance)
:SlotImpl()
{
	m_owningInstance = par_owningInstance;
	m_owner = par_owningInstance;
}