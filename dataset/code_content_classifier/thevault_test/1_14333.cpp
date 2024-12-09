TypedElementImpl::TypedElementImpl(std::weak_ptr<uml::Namespace > par_namespace)
:TypedElementImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}