ContinuationImpl::ContinuationImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand)
:ContinuationImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}