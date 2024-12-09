ConsiderIgnoreFragmentImpl::ConsiderIgnoreFragmentImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand)
:ConsiderIgnoreFragmentImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}