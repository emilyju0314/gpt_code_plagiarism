ModelImpl::ModelImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ModelImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}