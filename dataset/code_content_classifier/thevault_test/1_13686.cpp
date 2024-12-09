LiteralIntegerImpl::LiteralIntegerImpl(std::weak_ptr<uml::Namespace > par_namespace)
:LiteralIntegerImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}