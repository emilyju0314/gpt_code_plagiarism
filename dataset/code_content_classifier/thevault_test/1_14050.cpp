LiteralStringImpl::LiteralStringImpl(std::weak_ptr<uml::Namespace > par_namespace)
:LiteralStringImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}