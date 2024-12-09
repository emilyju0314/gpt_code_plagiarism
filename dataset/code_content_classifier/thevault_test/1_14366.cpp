CombinedFragmentImpl::CombinedFragmentImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand)
:CombinedFragmentImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}