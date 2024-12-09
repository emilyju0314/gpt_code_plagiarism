DurationIntervalImpl::DurationIntervalImpl(std::weak_ptr<uml::Slot > par_owningSlot)
:DurationIntervalImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}