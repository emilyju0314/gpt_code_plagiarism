ReduceActionImpl::ReduceActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ReduceActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}