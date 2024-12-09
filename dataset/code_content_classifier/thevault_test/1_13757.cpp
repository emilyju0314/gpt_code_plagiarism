EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::Enumeration > par_enumeration)
:EnumerationLiteralImpl()
{
	m_enumeration = par_enumeration;
	m_namespace = par_enumeration;
}