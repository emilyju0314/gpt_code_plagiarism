VertexImpl::VertexImpl(std::weak_ptr<uml::Region > par_container)
:VertexImpl()
{
	m_container = par_container;
	m_namespace = par_container;
}