OpaqueExpressionImpl::OpaqueExpressionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:OpaqueExpressionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}