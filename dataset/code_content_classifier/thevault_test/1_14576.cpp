AbstractionImpl::AbstractionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:AbstractionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}