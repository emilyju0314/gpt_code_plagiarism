ConditionalNodeImpl::ConditionalNodeImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ConditionalNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}