ActivityEdgeImpl::ActivityEdgeImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ActivityEdgeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}