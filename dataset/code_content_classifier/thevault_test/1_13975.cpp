InteractionUseImpl::InteractionUseImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand)
:InteractionUseImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}