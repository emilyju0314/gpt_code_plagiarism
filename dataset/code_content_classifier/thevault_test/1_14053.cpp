LiteralStringImpl::LiteralStringImpl(std::weak_ptr<uml::Slot > par_owningSlot)
:LiteralStringImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}