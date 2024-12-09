DestroyObjectActionImpl::DestroyObjectActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:DestroyObjectActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}