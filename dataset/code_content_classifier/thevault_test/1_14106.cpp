ExpressionImpl::ExpressionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ExpressionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}