CreateObjectActionImpl::CreateObjectActionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:CreateObjectActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}