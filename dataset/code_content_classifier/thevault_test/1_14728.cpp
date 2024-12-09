ExpansionNodeImpl::ExpansionNodeImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ExpansionNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}