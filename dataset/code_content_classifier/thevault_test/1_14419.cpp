InstanceValueImpl::InstanceValueImpl(std::weak_ptr<uml::Slot > par_owningSlot)
:InstanceValueImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}