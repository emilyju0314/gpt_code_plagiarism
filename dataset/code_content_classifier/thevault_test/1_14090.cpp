InteractionImpl::InteractionImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand)
:InteractionImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}