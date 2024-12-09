TimeExpressionImpl::TimeExpressionImpl(std::weak_ptr<uml::Slot > par_owningSlot)
:TimeExpressionImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}