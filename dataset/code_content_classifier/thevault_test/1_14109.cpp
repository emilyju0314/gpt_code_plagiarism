ExpressionImpl::ExpressionImpl(std::weak_ptr<uml::Slot > par_owningSlot)
:ExpressionImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}