OpaqueExpressionImpl::OpaqueExpressionImpl(std::weak_ptr<uml::Slot > par_owningSlot)
:OpaqueExpressionImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}