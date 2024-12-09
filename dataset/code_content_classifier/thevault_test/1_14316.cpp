PseudostateImpl::PseudostateImpl(std::weak_ptr<uml::Region > par_container)
:PseudostateImpl()
{
	m_container = par_container;
	m_namespace = par_container;
}