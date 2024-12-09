NamedElementImpl::NamedElementImpl(std::weak_ptr<uml::Namespace > par_namespace)
:NamedElementImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}