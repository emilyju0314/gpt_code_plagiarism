VertexImpl::VertexImpl(std::weak_ptr<uml::Namespace > par_namespace)
:VertexImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}