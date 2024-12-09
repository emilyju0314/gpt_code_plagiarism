TimeExpressionImpl::TimeExpressionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:TimeExpressionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}