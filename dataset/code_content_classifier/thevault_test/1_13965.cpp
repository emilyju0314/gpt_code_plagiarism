IntervalImpl::IntervalImpl(std::weak_ptr<uml::Slot > par_owningSlot)
:IntervalImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}