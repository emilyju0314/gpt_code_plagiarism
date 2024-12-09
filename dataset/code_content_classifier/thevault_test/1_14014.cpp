StateInvariantImpl::StateInvariantImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand)
:StateInvariantImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}