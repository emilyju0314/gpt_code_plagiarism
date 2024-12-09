EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::Namespace > par_namespace)
:EnumerationLiteralImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}