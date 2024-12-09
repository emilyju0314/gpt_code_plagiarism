LiteralSpecificationImpl::LiteralSpecificationImpl(std::weak_ptr<uml::Slot > par_owningSlot)
:LiteralSpecificationImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}