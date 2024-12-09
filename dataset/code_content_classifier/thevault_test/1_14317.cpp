PseudostateImpl::PseudostateImpl(std::weak_ptr<uml::Namespace > par_namespace)
:PseudostateImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}