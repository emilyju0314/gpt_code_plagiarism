ObjectNodeImpl::ObjectNodeImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ObjectNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}