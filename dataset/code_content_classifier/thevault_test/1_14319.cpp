PseudostateImpl::PseudostateImpl(std::weak_ptr<uml::State > par_state)
:PseudostateImpl()
{
	m_state = par_state;
	m_namespace = par_state;
}