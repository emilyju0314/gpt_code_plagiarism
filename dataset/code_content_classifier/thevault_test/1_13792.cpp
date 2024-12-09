StructuredActivityNodeImpl::StructuredActivityNodeImpl(std::weak_ptr<uml::Namespace > par_namespace)
:StructuredActivityNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}