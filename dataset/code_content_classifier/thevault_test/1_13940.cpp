ReclassifyObjectActionImpl::ReclassifyObjectActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ReclassifyObjectActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}